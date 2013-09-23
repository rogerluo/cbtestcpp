dev c++ 中文支持：Illegal byte sequence

-finput-charset用来指定输入文件的的字符编码，如果不指定，将无法将L“中文"这样的字符正确转化为宽字符。相反，未指定输入文件的字符 编码时，MinGW编译环境下的gcc将按本地字符编码解析源文件，将普通字符串仍然按照文件使用的本地字符编码编入程序，并将含有宽字符标量L的字符串 按照本地编码来识别并转为UTF-8编码（很奇怪，它不是转为UNICODE编码，反而，在指定了源文件的字符集之后却转为了UTF-16编码。同时，这 种不指定源文件编码方式却使用宽字符标量L指明编译器要将特定字符串转换成UNICODE编码的行为将会带来一个警告，而不是编译报错）。

-fexec-charset指定了字符串所使用的格式。
比如说，如果源文件保存的是GBK格式的，那么编译成程序时，其中的字符串就是GBK编码的。但是如果你的程序其实需要字符串按UTF-8来编码，那么就可以指定编译选项-fexec-charset=UTF-8 -finput-charset=GBK

另外，windows中常见的UNICODE编码在这里应该写成UTF-16。linux中的UNICODE编码相应的就是UTF32了。

-fwide-exec-charset指定了C/C++中使用宽字符时的格式，默认的就是UTF-16或者UTF32，取决于你的系统中使用的宽字符格 式。（正如上面说的，windows使用UTF16的UNICODE编码，它是UCS2字符集的一个编编码格式；linux使用UTF32编码，是 UCS4的一个编码格式。相应的，windows中的编译器一般将wchar_t定为2个字节宽，而linux中的编译器一般定义wchar_t为4字节 宽。）

tortoisegit usage


http://msdn.microsoft.com/en-us/library/windows/desktop/dd373814.aspx
http://msdn.microsoft.com/en-us/library/windows/desktop/dd318716.aspx
http://www.unicode.org/iso15924/iso15924-codes.html

各个版本的区别
alpha版：内部测试版。α是希腊字母的第一个，表示最早的版本，一般用户不要下载这个版本，这个版本一般是作为技术预览的，很可能包含很多BUG，功能也不全，主要是给开发人员和测试人员测试和找BUG用的。
pre版：这个和alpha都属于预览版，但是这个公众也会很容易拿到，一般分M1，M2等。windows7 我想很多人都从M3开始关注的。
beta版：公开测试版。β是希腊字母的第二个，顾名思义，这个版本比alpha版发布得晚一些，这个版的软件其实已经很成熟了，大的BUG一般不会出现，面向公众测试，即“公测”，而且这个阶段版本的软件还可能会增加一些新的功能新的应用。
rc版：Release Candidate（候选版本），Candidate是候选人的意思，用在软件上就是候选版本。Release.Candidate.就是发行候选版本。和Beta版最大的差别在于Beta阶段会一直加入新的功能，但是到了RC版本，几乎就不会加入新的功能了，而主要着重于除错!该版本又较beta版更进一步了。
stable版：稳定版。这个一般商业软件中没有这个版本，据说是在开源软件中有这个版本。这个就是开源软件的最终发行版，用户可以放心大胆的用了。
RTM版：全称为Release to Manufacture。工厂版。改版程序已经固定，就差工厂包装、光盘印图案等工作了。
OEM版：厂商定制版。我们购买品牌机预装的就是oem版，呵呵，我的戴尔本就是装的vista oem版，自动激活。现在论坛里大量充斥着的就是各种各样的oem版了。
EVAL版：评估版。就是有30或者60天等使用期限的版本。
RTL版：Retail.(零售版)，这个版本就是真正发售的版本，有漂亮的包装、光盘、说明书等东西和高昂的价格。windows7上市时价钱一定也不会便宜的。
MSDN版：这个其实不是一个软件开发周期中的版本代号了，它是微软软件独有的，因为msdn的全称是”Microsoft Developer Network“。我们在论坛平常说msdn版更多意义上代表的是“原版””未修改版“的含义。

========================================
boost and complier

msvc12/vs2013 use boost.1.54 or higher
msvc11/vs2012 use boost.1.53 or higher
msvc10/vs2010 use boost.1.49 or higher

========================================
boost::thread

*prerequisite: 
	Boost.System(mandatory), Boost.DateTime(mandatory) and Boost.Chrono(option, depend on the configuration)

*marco:
	BOOST_ALL_NO_LIB
	BOOST_THREAD_NO_LIB 
	BOOST_THREAD_DYN_LINK to dynamically link to thread library.
	BOOST_THREAD_USE_DLL equal to BOOST_THREAD_DYN_LINK.
	BOOST_ALL_DYN_LINK to dynamically link to all libraries.
	BOOST_THREAD_USE_LIB to statically link to thread library.

*command
	vs2013 32bit: #>bjam toolset=msvc --build-type=complete --with-thread --with-chrono --with-date_time --with-system --build-dir=msvc/x86 --stagedir=msvc/x86
	vs2013 64bit: #>bjam toolset=msvc --build-type=complete --with-thread --with-chrono --with-date_time --with-system --build-dir=msvc/x64 --stagedir=msvc/x64 address-model=64

	vs2012 32bit: #>bjam toolset=msvc-11.0 --build-type=complete --with-thread --with-chrono --with-date_time --with-system --build-dir=msvc/x86 --stagedir=msvc/x86
	vs2012 64bit: #>bjam toolset=msvc-11.0 --build-type=complete --with-thread --with-chrono --with-date_time --with-system --stagedir=msvc/x64 address-model=64




