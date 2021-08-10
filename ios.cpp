// ios_base
class _CRTIMP2_PURE_IMPORT ios_base : public _Iosb<int> { // base class for ios
public:
    using openmode = int;


// basic_ios
class basic_ios : public ios_base



// ios
using ios           = basic_ios<char, char_traits<char>>;