#ifndef AED2_TESTS_
#define AED2_TESTS_

#include <iostream>
#include <sstream>
using namespace std;

string mt_bool_to_s(bool b) { return b ? "true" : "false"; }
#define MT_MAKE_ERROR(lhs, rhs, line) { ostringstream os;os << "error en linea " << (line) << endl;os << "   se esperaba: " << (rhs) << endl;os << "     se obtuvo: " << (lhs);throw os.str(); }
void mt_assert(bool lhs, bool rhs, int line) { if (lhs != rhs) { MT_MAKE_ERROR(mt_bool_to_s(lhs), mt_bool_to_s(rhs), line) } }
void mt_assert(int lhs, int rhs, int line) { if (lhs != rhs) { MT_MAKE_ERROR(lhs, rhs, line) } }
void mt_assert(string lhs, string rhs, int line) { if (lhs.compare(rhs) != 0) { MT_MAKE_ERROR(lhs, rhs, line) } }
void mt_assert(const char* lhs, const char* rhs, int line) { mt_assert(string(lhs), string(rhs), line); }
#define RUN_TEST(test) {\
	{bool ok = true;\
	cout << #test << "..." << flush;\
	try { test(); }\
	catch (string& msg) { ok = false; cout << msg; } \
	catch (...) { ok = false; cout << "error"; }\
	if (ok) { cout << "ok"; }\
	cout << endl << flush;\
	}\
}
#define ASSERT_EQ(lhs, rhs) { mt_assert((lhs), (rhs), __LINE__); }
#define ASSERT(expr) { mt_assert((expr), true, __LINE__); }

#endif //AED2_TESTS_