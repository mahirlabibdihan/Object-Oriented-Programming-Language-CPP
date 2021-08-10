/*
 ______   _________ _      _       _
|  ____ \|___   ___| |    | |     | |
| |    \ \   | |   | |____| |     | |
| |    | |   | |   |  ____  |     | |
| |____/ /___| |___| |    | |_____| |
|_______/|_________|_|    |_________|
M A H I R     L A B I B     D I H A N

*/
/*
// xiosbase internal header


// CLASS TEMPLATE _Iosb
template <class _Dummy>
class _Iosb {
    enum _Openmode { // constants for file opening options
        _Openmask = 0xff
    };

    static constexpr _Openmode in         = static_cast<_Openmode>(0x01); // 00001
    static constexpr _Openmode out        = static_cast<_Openmode>(0x02); // 00010
    static constexpr _Openmode ate        = static_cast<_Openmode>(0x04); // 00100
    static constexpr _Openmode app        = static_cast<_Openmode>(0x08); // 01000
    static constexpr _Openmode trunc      = static_cast<_Openmode>(0x10); // 01010
    static constexpr _Openmode binary     = static_cast<_Openmode>(0x20); // 10100
    static constexpr _Openmode _Nocreate  = static_cast<_Openmode>(0x40);
    static constexpr _Openmode _Noreplace = static_cast<_Openmode>(0x80);

}


// ios_base
class _CRTIMP2_PURE_IMPORT ios_base : public _Iosb<int> { // base class for ios
public:
    using openmode = int;

}


// basic_ios
class basic_ios : public ios_base{

}



// ios
using ios           = basic_ios<char, char_traits<char>>;

*/

/*
    ios::in     : (input) Allow input operations on the stream.
    ios::out    : (output) Allow output operations on the stream.
    ios::trunc  : (truncate) Any current content is discarded, assuming a length of zero on opening.
    ios::app    : (append) Set the stream's position indicator to the end of the stream before each output operation.
    ios::ate    : (at end) Set the stream's position indicator to the end of the stream on opening.
    ios::binary : (binary) Consider stream as binary rather than text.
*/
#include <iostream>
#include <fstream>
using namespace std;
int main() {
    /***** 1 *****/
    // ios::in  : Allows input operations on the stream

    // ios::in is the default openmode for ifstream
    // void ifstream::open(const char *filename,openmode mode=ios::in);
    
    // ifstream input("file.txt");     // same as ifstream input("file.txt",ios::in);
    // char ch;
    // input>>ch;
    // cout<<ch;
    // input.close();

    // If we open ftream with just ios::in, we can only read the file. Can't write to it.
    // fstream input("file.txt",ios::in);  
    // char ch;
    // input>>ch;
    // cout<<ch;
    // input.close();

    // Normally we don't need to specify ios::in for ifstream. 
    // But when we want to use multiple openmode we have OR them with ios::in
    // 

    /***** 2 *****/
    // ios::out : Allow output operations on the stream. (Will remove file all contents if used single.By default, an output file opens in "truncate" mode which dumps all of the file's current contents)
    // ios::out is the default openmode for ofstream
    // void ofstream::open(const char *filename,openmode mode=ios::out);
    
    // ofstream output("file.txt");    // same as ofstream output("file.txt",ios::out);

    // If we open fstream with just ios::out, we can only write the file. Can't read from it.
    // fstream output("file.txt",ios::out);   
    // output<<"Z";
    // output.close();


    // ios::out|ios::in is the default openmode for fstream
    // void fstream::open(const char *filename,openmode mode=ios::in|ios::out);
    // fstream inout("file.txt");      // same as fstream output("file.txt",ios::in|ios::out);
    // If we use ios::in|ios::out it won't remove files content.
    // But if we just use ios::out it will remove files content.
    // If we use ios::in|ios::out and write to the file. The writing will start from beginning of the file.
    // Thus it will replace the previous content.
    // We have file.txt: Dihan
    // We write 'Z' to it.
    // It will become Zihan 

    /***** 3 *****/
    // ios::app:  Set the stream's position indicator to the end of the stream before each output operation.
    // Works with ofstream(While writing). Won't work if we use it with ios::in.
    // ofstream output("file.txt",ios::out|ios::app);
    // output.seekp(0,ios::beg);    
    // output<<"Z";    
    // output.close();
    // If we use ios::app with ios::out the file's content won't be deleted.
    // With ios::app the write position in the file is "sticky" -- all writes are at the end, no matter where you seek.
    // When ios::app is set, all output operations are performed at the end of the file. Since all writes are implicitly preceded by seeks, there is no way to write elsewhere.

    // If we open file with ios::app. And seek to beginning and write to file. It will still write at the end of the file.
    // Because ios::app seek to end(automatically. And there's nothing we can do about it.) before each write.

    /***** 4 *****/
    // ios::ate: Set the stream's position indicator to the end of the stream on opening.
    // Works with ifstream and fstream. 
    // Also works with ofstream. But when we open a file for oftream it deletes that files whole content. 
    // So it doesn't matter if we set the position at end of file.
    // ifstream input("file.txt",ios::in|ios::ate);
    // cout<<input.get();  // eof
    // input.close();  

    // fstream inout("file.txt",ios::in|ios::out|ios::ate);
    // inout<<'n';
    // inout.seekp(0,ios::beg);
    // inout<<'Z';
    // inout.close();




    // Will start reading from end of file. But we can change the read position using seek.

    /***** 5 *****/
    // ios::trunc  : (truncate) Any current content is discarded, assuming a length of zero on opening.
    // It doesn't work with ifstream. Because in ifstream we open a file for reading. We can not modify the file. And trunc modifies the file by removing its content. That's not possible with ifstream.

    // In ofstream ios::out already removes files content. So it doesn't matter if we use ios::trunc or not.

    // But in fstream
    // fstream inout("file.txt");      // same as fstream output("file.txt",ios::in|ios::out);
    // If we use ios::in|ios::out it won't remove files content.
    // But if we just use ios::out it will remove files content.
    // So if we want to use ios::in|ios::out, and we also want to remove file's content, we can use ios::trunc.
    // fstream inout("file.txt",ios::in|ios::out|ios::trunc);  
    // In this we way we can open a file for read and write. Also the file's content will be cleared.
    // So, ios::trunc useful when we want to read a file and also removes its contents. We have to use fstream for that. We can't use ifstream.
}