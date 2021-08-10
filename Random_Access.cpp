We should open binary files for random access.
But if we open text file it will also be valid.
But we will face problem if you random access in text file.
Because we know new lines translated to '\r\n' which holds 2 bytes.
So it creates when we try to randomly access in text mode.

---------------
File.txt:
---------------
Dihan
a
---------------


If we look at this file we will think that,
'n' is at 5th(offset:4) position,
new line('\n') is at 6th position,
'a' is at 7th position.


But.... 



in.seekg(4,ios::beg);
cout<<in.get();
in.seekg(5,ios::beg);
cout<<in.get();
in.seekg(6,ios::beg);
cout<<in.get();
in.seekg(7,ios::beg);
cout<<in.get();

Output: (if we open this file in text mode.)
110 ('n')
10 ('\n')
10 ('\n')
97 ('a')



Output: (if we open this file in binary mode.)
110 ('n')
13 ('\r')
10 ('\n')
97 ('a')
