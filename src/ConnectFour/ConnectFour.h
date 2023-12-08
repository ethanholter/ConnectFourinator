#include <string>

class ConnectFour {
private:
  // 0 = empty, 1=player, 2=computer.
  std::string board{"0000000000000000000000000000000000000000000000000"};
  int turn;

public:
  ConnectFour(bool playerFirst = true);
  ~ConnectFour();

  void completeMove(int column);
  void addPiece(int column);

  // ------ UTILITY FUNCTIONS ------

  void printBoard() const;
  std::string toString() const;
  int checkWin() const;

  // ------ GETTERS ------

  std::string getBoard() const;
  int getTurn() const;
  int getPiece(int row, int column) const;

  // ------ STATIC METHODS ------

  static std::string addPiece(const std::string &boardState, int column,
                              int turn);
  static int checkWin(const std::string &boardState);
  static int getPiece(const std::string &boardState, int row, int column);
  static std::string emptyBoard();
};
