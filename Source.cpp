// kursor 08/04/17
//OOP
// статья "Programming stuff " @sergey teplyakov обязательне прочитать

//prog 1
/*
#include <iostream>

class abc
{

public:									// < - Дает доступ к классу
	abc(const int x)
	{
		i = x;
	}
	void print(void) const             // < - константный метод объявления 
	{
		std::cout << i << std::endl;
	}
private:
	int i;
};

int main(void)
{
	const abc x = 1234567;
	x.print();
}
*/

//prog 1(1)
/*
#include <iostream>

class abc
{

public:
	abc(void)                          // < - конструктор по умлочанию( без параметров)
	{
		i = 123456;
	}
	void print(void) const
	{
		std::cout << i << std::endl;
	}
private:
	int i;
};

int main(void)
{
	const abc x;
	x.print();
}
*/

//prog 1(2)
/*
#include <iostream>

class abc
{

public:
	void print(void) const
	{
		std::cout << i << std::endl;
	}
private:
	int i{};							// < - не явная инициализация
};

int main(void)
{
	const abc x;
	x.print();
}
*/

//prog 1(3)
/*
#include <iostream>

class abc
{

public:
	abc(const int x)
	{
		i = x;
	}
	void print(void) const
	{
		std::cout << i << std::endl;
	}
private:
	int i{};
};

int main(void)
{
	const abc x = 1234567;
	x.print();
}
*/

//prog 1(4)
/*
#include <iostream>

class abc
{
public:
	explicit abc(const int i)  // < - "explicit" запрет на не явное преобразование
	{
		this->i = i;  // < - "this" - позваляет указать именно к области видимости класса
	}
	void print(void) const
	{
		std::cout << i << std::endl;
	}
private:
	int i{};
};

int main(void)
{
	const abc x  { 1234567 };
	x.print();
}
*/

//prog 1(5)
/*
#include <iostream>

class abc
{
public:
	explicit abc(const char c, const int i, const float f) 
	{
		abc::c = c;
		abc::i = i;
		abc::f = f;
	}
	void print(void) const
	{
		std::cout << c << ' ' << i << ' ' << f << std::endl;
	}
private:
	char c;
	int i;
	float f;
};

int main(void)
{
	const abc x('a', 1234567, 3.14f);
	x.print();
}
*/

//prog 1(6)
/*
#include <iostream>

class abc
{
public:
	explicit abc(const char c, const int i, const float f) : c(c), i(i), f(f) // <- правила разришения имен "с" - относится к классу абц / "(с)" - параметер конструктора
	{}																		  // <- упрощение конструктора 

	void print(void) const
	{
		std::cout << c << ' ' << i << ' ' << f << std::endl;
	}
private:																	 // <- список инициализации
	char c;
	int i;
	float f;
};

int main(void)
{
	const abc x('a', 1234567, 3.14f);
	x.print();
}
*/

//prog 1(7)
/*
#include <iostream>

class abc
{
public:
	explicit abc(const char c, const int i, const float f) : c{c}, i{i}, f{f} // <- инициализация списком
	{}

	void print(void) const
	{
		std::cout << c << ' ' << i << ' ' << f << std::endl;
	}
private:
	char c;
	int i;
	float f;
};

int main(void)
{
	const abc x('a', 1234567, 3.14f);
	x.print();
}
*/

//prog 1(8)
/*
#include <iostream>

class abc
{
public:
	explicit abc(const char c, const int i, const float f) : c{ c }, i{ i }, f{ f } // <- инициализация списком
	{}

	explicit abc(const abc& x) : c{ x.c }, i{ x.i }, f{ x.f } // <- конструктор копирования (явный)
	{}

	void print(void) const
	{
		std::cout << c << ' ' << i << ' ' << f << std::endl;
	}
private:
	char c;
	int i;
	float f;
};

int main(void)
{
	const abc x('a', 1234567, 3.14f);
	x.print();
	const abc y (x);  // <- фунцианальная инициализация
	y.print();
}
*/

//prog 1(9)
/*
#include <iostream>

class abc
{
public:
	explicit abc(const char c, const int i, const float f) : c{ c }, i{ i }, f{ f } // <- инициализация списком
	{}

	explicit abc(const abc& x) : c{ x.c }, i{ x.i }, f{ x.f } // <- конструктор копирования (явный)
	{}

	void print(void) const
	{
		std::cout << c << ' ' << i << ' ' << f << ' ' << s << std::endl;
	}
private:
	char c;
	int i;
	float f;

public:
	static int s; // < - статический член класса
};

int main(void)
{
	std::cout << abc::s << std::endl; 

	const abc x('a', 1111111, 1.11f);
	x.print();
	const abc y('b', 2222222, 2.22f);
	y.print();
}

int abc::s(77777);
*/

//prog 1(10)
/*
#include <iostream>

class abc
{
public:
	explicit abc(const char c, const int i, const float f) : c{ c }, i{ i }, f{ f }
	{}

	explicit abc(const abc& x) : c{ x.c }, i{ x.i }, f{ x.f }
	{}

	~abc(void)												  // <- если в классе отсутсвует деструктор,то компилятор задает не явный деструктор
	{}														  // <- у деструктора отсутстувуют параметры

	void print(void) const
	{
		std::cout << c << ' ' << i << ' ' << f << std::endl;
	}
private:
	char c;
	int i;
	float f;

public:
	static int s; // < - статический член класса
};

int main(void)
{
	const abc x('a', 1111111, 1.11f);
	x.print();
	const abc y('b', 2222222, 2.22f);
	y.print();
}
*/

//prgo 1(11)
/*
#include <iostream>

class abc
{
public:
	explicit abc(const char c, const int i, const float f) : c{ c }, i{ i }, f{ f }
	{
		std::cout << "abc(" << c << ' ' << i << ' ' << f << ")" << std::endl;
	}

	explicit abc(const abc& x) : c{ x.c }, i{ x.i }, f{ x.f }
	{
		std::cout << "abc({" << c << ' ' << i << ' ' << f << "})" << std::endl;
	}

	~abc(void)												  // <- если в классе отсутсвует деструктор,то компилятор задает не явный деструктор
	{
		std::cout << "abc(" << c << ' ' << i << ' ' << f << ")" << std::endl;
	}														  // <- у деструктора отсутстувуют параметры

	void print(void) const
	{
		std::cout << c << ' ' << i << ' ' << f << std::endl;
	}
private:
	char c;
	int i;
	float f;

public:
	static int s; // < - статический член класса
};

int main(void)
{
	const abc x('a', 1111111, 1.11f);
	x.print();
	const abc y(x);
	y.print();
}
*/

//pgor 1(11)
/*
#include <iostream>

class abc
{
public:
	explicit abc(const char c, const int i, const float f) : c{ c }, i{ i }, f{ f }
	{
		std::cout << "abc(" << c << ' ' << i << ' ' << f << ")" << std::endl;
	}

	explicit abc(const abc& x) = default;

	~abc(void)												  // <- если в классе отсутсвует деструктор,то компилятор задает не явный деструктор
	{
		std::cout << "abc(" << c << ' ' << i << ' ' << f << ")" << std::endl;
	}														  // <- у деструктора отсутстувуют параметры

	void print(void) const
	{
		std::cout << c << ' ' << i << ' ' << f << std::endl;
	}
private:
	char c;
	int i;
	float f;

public:
	static int s; // < - статический член класса
};

int main(void)
{
	const abc x('a', 1111111, 1.11f);
	x.print();
	const abc y(x);
	y.print();
}
*/

//prog 1(12)
/*
#include <iostream>

class abc
{
public:
	explicit abc(const char c, const int i, const float f) : c{ c }, i{ i }, f{ f }
	{
		std::cout << "abc(" << c << ' ' << i << ' ' << f << ")" << std::endl;
	}

	explicit abc(const abc&) = delete;						  //<- запрет на создание конструктора копирования поумлочанию

	~abc(void)												  // <- если в классе отсутсвует деструктор,то компилятор задает не явный деструктор
	{
		std::cout << "abc(" << c << ' ' << i << ' ' << f << ")" << std::endl;
	}

	void print(void) const
	{
		std::cout << c << ' ' << i << ' ' << f << std::endl;
	}
private:
	char c;
	int i;
	float f;

public:
	static int s; // < - статический член класса
};

int main(void)
{
	const abc x('a', 1111111, 1.11f);
	x.print();
	const abc y(x);
	y.print();
}
*/

//prog 1(13)
/*
#include <iostream>

class abc
{
public:
	explicit abc(void)
	{
		std::cout << "abc()" << std::endl;                     // <- конструктор по умлочании
	}

	explicit abc(const char c, const int i, const float f) : c{ c }, i{ i }, f{ f }
	{
		std::cout << "abc(" << c << ' ' << i << ' ' << f << ")" << std::endl;
	}

	explicit abc(const abc&) = delete;
	abc& operator = (const abc&) = default;

	~abc(void)
	{
		std::cout << "abc(" << c << ' ' << i << ' ' << f << ")" << std::endl;
	}

	void print(void) const
	{
		std::cout << c << ' ' << i << ' ' << f << std::endl;
	}

private:
	char c;
	int i;
	float f;
};

int main(void)
{
	const abc x('a', 1111111, 1.11f);
	x.print();
	abc y;
	y = x;
	y.print();
}
*/

//prog 1(14)

#include <iostream>

class abc
{
public:
	abc(void): abc(0, 0, 0)                                   // механизм делегрования конструкторов (тут три конструктора)
	{
		std::cout << "abc()" << std::endl;
	}

	explicit abc(const char c, const int i, const float f) : c{ c }, i{ i }, f{ f }
	{
		std::cout << "abc(" << c << ' ' << i << ' ' << f << ")" << std::endl;
	}

	explicit abc(const abc& x): abc(x.c, x.i, x.f)          // <- вызов второго конструктора(делегируещего)
	{
		std::cout << "abc({" << c << ' ' << i << ' ' << f << "})" << std::endl;
	}

	void print(void) const
	{
		std::cout << c << ' ' << i << ' ' << f << std::endl;
	}

private:
	char c;
	int i;
	float f;
};

int main(void)
{
	const int i(1234567);                  // предотвращение сужение типов !!!!!!! ибо теряется потеря точности!!! 
	std::cout << i << std::endl;
	unsigned char c{ i };
	int j(c);
	std::cout << j << std::endl;
}
