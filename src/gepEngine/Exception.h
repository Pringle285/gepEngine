#include <exception>
#include <string>

namespace gepEngine
{

struct Exception : public std::exception
{
  Exception(const std::string& message);
  virtual ~Exception() throw();
  virtual const char* what() const throw();

private:
  std::string message;

};

void pollForError();

}
