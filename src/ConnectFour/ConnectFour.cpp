#include "ConnectFour.h"
#include <iostream>
#include <stdexcept>
#include <string>

ConnectFour::ConnectFour(bool playerFirst) { turn = playerFirst ? 0 : 1; }

ConnectFour::~ConnectFour() {}

std::string ConnectFour::toString() const {
  std::string result = "";
  for (int i = 0; i < 6; i++) {
    result += "|";
    for (int j = 0; j < 7; j++) {
      result += getPiece(i, j) == -1 ? " " : getPiece(i, j) == 0 ? "X" : "O";
      result += "|";
    }
    result += "\n";
  }
  return result;
}

void ConnectFour::printBoard() const { std::cout << toString(); }

std::string ConnectFour::addPiece(const std::string &boardState, int column,
                                  int turn) {
  if (column < 0 || column > 6) {
    std::cout << "Invalid column\n";
    return boardState;
  }

  if (boardState[column] == 1) {
    return boardState;
  }

  std::string newBoardState = boardState;

  // iterate from bottom to top
  for (int i = 5; i >= 0; i--) {

    // if empty, add piece and switch turn
    if (getPiece(boardState, i, column) == -1) {
      newBoardState[7 * i + column] = turn == 0 ? '1' : '2';
      return newBoardState;
    }
  }

  throw std::invalid_argument("invalid board state");
}

void ConnectFour::addPiece(int column) {
  board = addPiece(board, column, turn);
}

void ConnectFour::completeMove(int column) {

  // check if column is valid
  if (column < 0 || column > 6) {
    std::cout << "Invalid column\n";
    return;
  }

  // iterate from bottom to top
  for (int i = 5; i >= 0; i--) {

    // if empty, add piece and switch turn
    if (getPiece(i, column) == -1) {
      addPiece(column);
      turn = turn == 0 ? 1 : 0;
      return;
    }
  }
  std::cout << "Column is full\n";
}

// return -1 if empty, 0 if player, 1 if computer
int ConnectFour::getPiece(int row, int column) const {
  int x = board[7 * row + column];
  switch (x) {
  case '0':
    return -1;
    break;
  case '1':
    return 0;
    break;
  case '2':
    return 1;
    break;
  default:
    throw std::invalid_argument("Invalid board state");
  }
}

int ConnectFour::getTurn() const { return turn; }

// return -1 if no winner, 0 if player, 1 if computer
int ConnectFour::checkWin() const {
  // check horizontal
  for (int row = 0; row < 6; row++) {
    int playerCount = 0;
    int computerCount = 0;
    for (int col = 0; col < 7; col++) {

      if (getPiece(row, col) == 0) {
        playerCount++;
        computerCount = 0;
      } else if (getPiece(row, col) == 1) {
        computerCount++;
        playerCount = 0;
      } else {
        playerCount = 0;
        computerCount = 0;
      }

      // check for winner
      if (playerCount == 4) {
        return 0;
      } else if (computerCount == 4) {
        return 1;
      }
    }
  }

  // check vertical
  for (int col = 0; col < 7; col++) {
    int playerCount = 0;
    int computerCount = 0;
    for (int row = 0; row < 6; row++) {
      if (getPiece(row, col) == 0) {
        playerCount++;
        computerCount = 0;
      } else if (getPiece(row, col) == 1) {
        computerCount++;
        playerCount = 0;
      } else {
        playerCount = 0;
        computerCount = 0;
      }

      // check for winner
      if (playerCount == 4) {
        return 0;
      } else if (computerCount == 4) {
        return 1;
      }
    }
  }

  // check diagonal (top right to bottom left)
  int startCoordsTL[6][2] = {{2, 0}, {1, 0}, {0, 0}, {0, 1}, {0, 2}, {0, 3}};

  // check diagonal (top left to bottom right)
  for (int diag = 0; diag < 6; diag++) {
    int row = startCoordsTL[diag][0];
    int col = startCoordsTL[diag][1];

    int playerCount = 0;
    int computerCount = 0;

    while (row < 6 && col < 7) {
      if (getPiece(row, col) == 0) {
        playerCount++;
        computerCount = 0;
      } else if (getPiece(row, col) == 1) {
        computerCount++;
        playerCount = 0;
      } else {
        playerCount = 0;
        computerCount = 0;
      }

      // check for winner
      if (playerCount == 4) {
        return 0;
      } else if (computerCount == 4) {
        return 1;
      }

      row++;
      col++;
    }
  }

  // check diagonal (bottom right to top left)
  int startCoordsBR[6][2] = {{3, 6}, {4, 6}, {5, 6}, {5, 5}, {4, 5}, {3, 5}};

  // check diagonal (bottom right to top left)
  for (int diag = 0; diag < 5; diag++) {
    int row = startCoordsBR[diag][0];
    int col = startCoordsBR[diag][1];

    int playerCount = 0;
    int computerCount = 0;

    while (row >= 0 && col >= 0) {
      if (getPiece(row, col) == 0) {
        playerCount++;
        computerCount = 0;
      } else if (getPiece(row, col) == 1) {
        computerCount++;
        playerCount = 0;
      } else {
        playerCount = 0;
        computerCount = 0;
      }

      // check for winner
      if (playerCount == 4) {
        return 0;
      } else if (computerCount == 4) {
        return 1;
      }

      row--;
      col--;
    }
  }

  return -1;
}

std::string ConnectFour::getBoard() const { return board; }
