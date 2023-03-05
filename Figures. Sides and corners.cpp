// Figures. Sides and corners.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include<string>
#include <iostream>
class Figure
{
protected:
	std::string nameOfFigure;
	int haveSides = 3;
	int sideLengthA= 0;
	int sideLengthB = 0;
	int sideLengthC = 0;
	int sideLengthD = 0;
	int angleA = 0;
	int angleB = 0;
	int angleC = 0;
	int angleD = 0;
public:
	std::string getNameOfFigure() { return nameOfFigure; }
	int getSides() { return haveSides; }

	int getSideLengthA() { return sideLengthA; }
	int getSideLengthB() { return sideLengthB; }
	int getSideLengthC() { return sideLengthC; }
	int getSideLengthD() { return sideLengthD; }

	int getAngleA() { return angleA; }
	int getAngleB() { return angleB; }
	int getAngleC() { return angleC; }
	int getAngleD() { return angleD; }
};
class Triangle : public Figure
{
public:
	Triangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
	{
		nameOfFigure = "Треугольник";
		this->sideLengthA= sideLengthA;
		this->sideLengthB = sideLengthB;
		this->sideLengthC = sideLengthC;
		this->angleA = angleA;
		this->angleB = angleB;
		this->angleC = angleC;
	}
};

class rightTriangle : public Triangle
{
public:
	rightTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB)
		: Triangle(sideLengthA, sideLengthB, sideLengthC, angleA, angleB, 90)
	{
		Triangle::nameOfFigure = "Прямоугольный треугольник";
	};
};
class isoscelesTriangle : public Triangle
{
public:
	isoscelesTriangle(int sideLengthA, int sideLengthB, int angleA, int angleB)
		: Triangle(sideLengthA, sideLengthB, sideLengthA, angleA, angleB, angleA)
	{
		Triangle::nameOfFigure = "Равнобедренный треугольник";
	};
};
class equilateralTriangle : public Triangle
{
public:
	equilateralTriangle(int sideLengthA)
		: Triangle(sideLengthA, sideLengthA, sideLengthA, 60, 60, 60)
	{
		Triangle::nameOfFigure = "Равносторонний треугольник";
	};
};
class Quadrilateral : public Figure
{

public:
	Quadrilateral(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
	{
		nameOfFigure = "Четырехугольник";

		haveSides =4;

		this->sideLengthA = sideLengthA;
		this->sideLengthB = sideLengthB;
		this->sideLengthC = sideLengthC;
		this->sideLengthD = sideLengthD;

		this->angleA = angleA;
		this->angleB = angleB;
		this->angleC = angleC;
		this->angleD = angleD;
	}
};
class Rectangle : public Quadrilateral
{
public: //int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD
	Rectangle(int sideLengthA, int sideLengthB)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthA, sideLengthB, 90, 90, 90, 90)
				{
 Quadrilateral::nameOfFigure = "Прямоугольник";
}
};
class Square : public Quadrilateral
{
public:
	Square(int sideLengthA)
		: Quadrilateral(sideLengthA, sideLengthA, sideLengthA, sideLengthA, 90, 90, 90, 90)
	{
		Quadrilateral::nameOfFigure = "Квадрат";
	}
};

class Parallelogram : public Quadrilateral
{
public:
	Parallelogram(int sideLengthA, int sideLengthB, int angleA, int angleB)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthA, sideLengthB, angleA, angleB, angleA, angleB)
	{
		Quadrilateral::nameOfFigure = "Параллелограмм";
	}
};
class Rhomb : public Quadrilateral
{
public:
	Rhomb(int sideLengthA, int angleA, int angleB)
		: Quadrilateral(sideLengthA, sideLengthA, sideLengthA, sideLengthA, angleA, angleB, angleA, angleB)
	{
		Quadrilateral::nameOfFigure = "Ромб";
	}
};
void printFigure(Figure& figure)
{
	std::cout << std::endl;
	std::cout << figure.getNameOfFigure() << ":" << std::endl;

	std::cout << "Стороны:";
	std::cout << " a = " << figure.getSideLengthA() << ", b = " << figure.getSideLengthB() << ", с = " << figure.getSideLengthC();
	if (figure.getSides()==3)
	{
		std::cout << ", d = " << figure.getSideLengthD() << std::endl;
	}
	else { std::cout << std::endl; }

	std::cout << "Углы:";
	std::cout << " А = " << figure.getAngleA() << ", В = " << figure.getAngleB() << ", С = " << figure.getAngleC();
	if (figure.getSides()==4) { std::cout << ", D = " << figure.getAngleD() << std::endl; }
	else { std::cout << std::endl; }
}


int main()
{
	setlocale(LC_ALL, "Russian"); //Корректное отображение Кириллицы
	system("chcp 1251");

	Triangle Triangle1(10, 20, 30, 50,60, 60);
	printFigure(Triangle1);

	rightTriangle rightTriangle1(10, 20, 30, 40, 50);
	printFigure(rightTriangle1);

	isoscelesTriangle isoscelesTriangle1(10, 50, 60, 50);
	printFigure(isoscelesTriangle1);

	equilateralTriangle equilateralTriangle1(30);
	printFigure(equilateralTriangle1);

	Quadrilateral Quadrilateral1(10, 20, 30, 40, 50, 60, 70, 80);
	printFigure(Quadrilateral1);

	Rectangle Rectangle1(10, 20);
	printFigure(Rectangle1);

	Square Square1(30);
	printFigure(Square1);

	Parallelogram Parallelogram1(20, 30, 30, 40);
	printFigure(Parallelogram1);

	Rhomb Rhomb1(30, 30, 40);
	printFigure(Rhomb1);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
