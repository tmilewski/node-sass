#define SASS_BACKTRACE

#include <sstream>

#ifndef SASS_NODE
#define SASS_NODE
#endif

namespace Sass {

  using namespace std;

  struct Backtrace {

    Backtrace* parent;
    string     path;
    size_t     line;
    string     caller;

    Backtrace(Backtrace* prn, string pth, size_t ln, string c)
    : parent(prn),
      path(pth),
      line(ln),
      caller(c)
    { }

    string to_string()
    {
      stringstream ss;
      Backtrace* this_point = this;

      ss << endl << "Backtrace:";
      // the first tracepoint (which is parentless) is an empty placeholder
      while (this_point->parent) {
        ss << endl
           << "\t"
           << this_point->caller
           << " in "
           << this_point->path
           << ":"
           << this_point->line;
        this_point = this_point->parent;
      }

      return ss.str();
    }

  };

}