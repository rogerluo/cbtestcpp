dev c++ ����֧�֣�Illegal byte sequence

-finput-charset����ָ�������ļ��ĵ��ַ����룬�����ָ�������޷���L������"�������ַ���ȷת��Ϊ���ַ����෴��δָ�������ļ����ַ� ����ʱ��MinGW���뻷���µ�gcc���������ַ��������Դ�ļ�������ͨ�ַ�����Ȼ�����ļ�ʹ�õı����ַ����������򣬲������п��ַ�����L���ַ��� ���ձ��ر�����ʶ��תΪUTF-8���루����֣�������תΪUNICODE���룬��������ָ����Դ�ļ����ַ���֮��ȴתΪ��UTF-16���롣ͬʱ���� �ֲ�ָ��Դ�ļ����뷽ʽȴʹ�ÿ��ַ�����Lָ��������Ҫ���ض��ַ���ת����UNICODE�������Ϊ�������һ�����棬�����Ǳ��뱨����

-fexec-charsetָ�����ַ�����ʹ�õĸ�ʽ��
����˵�����Դ�ļ��������GBK��ʽ�ģ���ô����ɳ���ʱ�����е��ַ�������GBK����ġ����������ĳ�����ʵ��Ҫ�ַ�����UTF-8�����룬��ô�Ϳ���ָ������ѡ��-fexec-charset=UTF-8 -finput-charset=GBK

���⣬windows�г�����UNICODE����������Ӧ��д��UTF-16��linux�е�UNICODE������Ӧ�ľ���UTF32�ˡ�

-fwide-exec-charsetָ����C/C++��ʹ�ÿ��ַ�ʱ�ĸ�ʽ��Ĭ�ϵľ���UTF-16����UTF32��ȡ�������ϵͳ��ʹ�õĿ��ַ��� ʽ������������˵�ģ�windowsʹ��UTF16��UNICODE���룬����UCS2�ַ�����һ��������ʽ��linuxʹ��UTF32���룬�� UCS4��һ�������ʽ����Ӧ�ģ�windows�еı�����һ�㽫wchar_t��Ϊ2���ֽڿ���linux�еı�����һ�㶨��wchar_tΪ4�ֽ� ����

tortoisegit usage


http://msdn.microsoft.com/en-us/library/windows/desktop/dd373814.aspx
http://msdn.microsoft.com/en-us/library/windows/desktop/dd318716.aspx
http://www.unicode.org/iso15924/iso15924-codes.html

�����汾������
alpha�棺�ڲ����԰档����ϣ����ĸ�ĵ�һ������ʾ����İ汾��һ���û���Ҫ��������汾������汾һ������Ϊ����Ԥ���ģ��ܿ��ܰ����ܶ�BUG������Ҳ��ȫ����Ҫ�Ǹ�������Ա�Ͳ�����Ա���Ժ���BUG�õġ�
pre�棺�����alpha������Ԥ���棬�����������Ҳ��������õ���һ���M1��M2�ȡ�windows7 ����ܶ��˶���M3��ʼ��ע�ġ�
beta�棺�������԰档����ϣ����ĸ�ĵڶ���������˼�壬����汾��alpha�淢������һЩ�������������ʵ�Ѿ��ܳ����ˣ����BUGһ�㲻����֣������ڲ��ԣ��������⡱����������׶ΰ汾����������ܻ�����һЩ�µĹ����µ�Ӧ�á�
rc�棺Release Candidate����ѡ�汾����Candidate�Ǻ�ѡ�˵���˼����������Ͼ��Ǻ�ѡ�汾��Release.Candidate.���Ƿ��к�ѡ�汾����Beta�����Ĳ������Beta�׶λ�һֱ�����µĹ��ܣ����ǵ���RC�汾�������Ͳ�������µĹ����ˣ�����Ҫ�����ڳ���!�ð汾�ֽ�beta�����һ���ˡ�
stable�棺�ȶ��档���һ����ҵ�����û������汾����˵���ڿ�Դ�����������汾��������ǿ�Դ��������շ��а棬�û����Է��Ĵ󵨵����ˡ�
RTM�棺ȫ��ΪRelease to Manufacture�������档�İ�����Ѿ��̶����Ͳ����װ������ӡͼ���ȹ����ˡ�
OEM�棺���̶��ư档���ǹ���Ʒ�ƻ�Ԥװ�ľ���oem�棬�Ǻǣ��ҵĴ���������װ��vista oem�棬�Զ����������̳���������ŵľ��Ǹ��ָ�����oem���ˡ�
EVAL�棺�����档������30����60���ʹ�����޵İ汾��
RTL�棺Retail.(���۰�)������汾�����������۵İ汾����Ư���İ�װ�����̡�˵����ȶ����͸߰��ļ۸�windows7����ʱ��Ǯһ��Ҳ������˵ġ�
MSDN�棺�����ʵ����һ��������������еİ汾�����ˣ�����΢��������еģ���Ϊmsdn��ȫ���ǡ�Microsoft Developer Network������������̳ƽ��˵msdn����������ϴ�����ǡ�ԭ�桱��δ�޸İ桰�ĺ��塣

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




