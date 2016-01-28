#include <iostream>
#include <cstring>

using namespace std;

class String
{
	public:
		    String(int n)
				    {
						        str = new char[n];
								    }

			    String(const char *p)
					    {
							        str = new char[strlen(p) + 1];
									        strcpy(str, p);
											    }

				    ~String()
						    {
								        delete[] str;   
										    }

					    void print() const
							    {
									        cout << str << endl;
											    }

						    int getlength() const
								    {
										        return strlen(str);
												    }

	private:
							    char *str;
};

int main()
{
	    String str1(100);               //OK 分配100个字节的空字符串
		    cout << str1.getlength() << " ";    str1.print();

			    String str2 = 100;              //编译通过 分配100个字节的空字符串
				    cout << str2.getlength() << " ";    str2.print();

					    String str3 = "464";            //编译通过 相当于String str3("464");
						    cout << str3.getlength() << " ";    str3.print();

							    return 0;
}
