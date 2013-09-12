dev c++ 中文支持：Illegal byte sequence

-finput-charset用来指定输入文件的的字符编码，如果不指定，将无法将L“中文"这样的字符正确转化为宽字符。相反，未指定输入文件的字符 编码时，MinGW编译环境下的gcc将按本地字符编码解析源文件，将普通字符串仍然按照文件使用的本地字符编码编入程序，并将含有宽字符标量L的字符串 按照本地编码来识别并转为UTF-8编码（很奇怪，它不是转为UNICODE编码，反而，在指定了源文件的字符集之后却转为了UTF-16编码。同时，这 种不指定源文件编码方式却使用宽字符标量L指明编译器要将特定字符串转换成UNICODE编码的行为将会带来一个警告，而不是编译报错）。

-fexec-charset指定了字符串所使用的格式。
比如说，如果源文件保存的是GBK格式的，那么编译成程序时，其中的字符串就是GBK编码的。但是如果你的程序其实需要字符串按UTF-8来编码，那么就可以指定编译选项-fexec-charset=UTF-8 -finput-charset=GBK

另外，windows中常见的UNICODE编码在这里应该写成UTF-16。linux中的UNICODE编码相应的就是UTF32了。

-fwide-exec-charset指定了C/C++中使用宽字符时的格式，默认的就是UTF-16或者UTF32，取决于你的系统中使用的宽字符格 式。（正如上面说的，windows使用UTF16的UNICODE编码，它是UCS2字符集的一个编编码格式；linux使用UTF32编码，是 UCS4的一个编码格式。相应的，windows中的编译器一般将wchar_t定为2个字节宽，而linux中的编译器一般定义wchar_t为4字节 宽。）

tortoisegit usage
