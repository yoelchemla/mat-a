#include "doctest.h"
#include "mat.hpp"
#include <string>
#include <algorithm>

using namespace ariel;
using namespace std;

string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("good input"){
	
CHECK(mat(9, 7, '@', '-') == nospaces(    "@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"     ));
 
CHECK(mat(3, 3, '!', '^') == nospaces(      "!!^\n"
                                             "^!^\n"
                                             "^!!"    ));


CHECK(mat(5, 5, '*', '?') == nospaces(      "????*\n"
                                             "*****\n"
                                             "?????\n"
                                             "*?*?*\n"
                                             "?*?*?"    ));

CHECK(mat(2, 1,'(', ')') == nospaces(       "()"
 ));

CHECK(mat(1, 1,'$', '_') == nospaces(       "$"
 ));

CHECK(mat(1, 2,'[', '}') == nospaces(       "}\n"
                                            "["
 ));



}



TEST_CASE("bad input"){

CHECK_THROWS(mat(10,  -5, '$', '%'));
CHECK_THROWS(mat(-11, -11, '#', '!'));
CHECK_THROWS(mat(-13, 13, '^', '-'));
CHECK_THROWS(mat(12, 5, '&', ':'));
CHECK_THROWS(mat(32, 6, '*', '('));
CHECK_THROWS(mat(100, 15, '(', ')'));
CHECK_THROWS(mat(2100, 52, '+', '%'));
CHECK_THROWS(mat(236, 13, '=', '%'));
CHECK_THROWS(mat(-252, 51, '!', '%'));
CHECK_THROWS(mat(-27, 40, '$', '$'));
CHECK_THROWS(mat(-1, -2, '&', '&'));
CHECK_THROWS(mat(3122, 66, '>', '|'));
CHECK_THROWS(mat(33338, 4, '<', '!'));
CHECK_THROWS(mat(1234, 34, '.', '#'));
CHECK_THROWS(mat(372, 10345, ':', ','));
CHECK_THROWS(mat(294, 543, ';', '='));
CHECK_THROWS(mat(414, 790, '"', '-'));
CHECK_THROWS(mat(436, 1111, '^', '_'));
CHECK_THROWS(mat(652, 99305, '|', '{'));
CHECK_THROWS(mat(-4, 332, ']', 's'));
CHECK_THROWS(mat(-49, 755, '[', '?'));
}
