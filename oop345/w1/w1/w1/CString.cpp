#include <iostream>
#include "CString.h"

static int c = 0;
namespace w1 {

	CString::CString(const char *string)
	{
		int n;
		for (n = 0; n < MAX && string[n] != '\0'; n++) {
			_string[n] = string[n];
		}
		_string[n] = '\0';
	}

	void CString::display(std::ostream &ostream) const
	{
		int n = 0;
		while (_string[n] != '\0') {
			ostream << _string[n++];
		}
	}

	std::ostream &operator<<(std::ostream &ostream, const CString &cstring)
	{
		ostream << c++ << ": ";
		cstring.display(ostream);
		return ostream;
	}
}