#include <stdexcept>
class LogFileException : public std::runtime_error
{
public:
  enum EState
  {
      es_NOT_INITIALIZED, es_COULD_NOT_OPEN_FILE, es_FILENAME_IS_EMPTY,
      es_FILE_NOT_FOUND, es_READ_ONLY, es_ACCESS_DENIED,
  };
  explicit LogFileException(EState state, const std::string &str = "")
      : runtime_error(str), state_(state)
  {
  }
  EState getState() { return state_; }

private:
  EState state_;
};