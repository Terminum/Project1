#include <iostream>
#include <vector>

class Point
{
private:
	double x, y;
public:

	Point() : x(0), y(0)
	{

	}

	void SetX()
	{
		std::cout << "Enter x - ";
		std::cin >> x;
	}

	void SetY()
	{
		std::cout << "Enter y - ";
		std::cin >> y;
	}

	double Getx()
	{
		return x;
	}
	double Gety()
	{
		return y;
	}
};

class MAN
{
private:
	double x, y, r;
public:
	MAN() : x(0), y(0), r(0)
	{
		std::cout << "Enter x - ";
		std::cin >> x;

		std::cout << "Enter y - ";
		std::cin >> y;

		std::cout << "Enter r - ";
		std::cin >> r;
	}

	bool Loc(Point p)
	{
		if (((x - p.Getx()) * (x - p.Getx())) + ((y - p.Gety()) * (y - p.Gety())) <= r * r) // (x-x0)^2+(y-y0)^2<=r^2
		{
			return 1;
		}
		else
			return 0;
	}

	int Dist(Point p)
	{
		return (((x - p.Getx()) * (x - p.Getx())) + ((y - p.Gety()) * (y - p.Gety()))); // x-x0)^2 + y-y0)^2 
	}

};



int main()
{
	std::cout << "Enter data for 1-st object." << std::endl;
	MAN O1;
	std::cout << "Enter data for 2-nd object." << std::endl;
	MAN O2;
	std::vector<Point> Dots;
	std::vector<bool> M1;
	std::vector<bool> M2;



	char c;
	std::cout << " <a> add point <m> choose best hand <p> - print hands <e> exit --> ";
	std::cin >> c;

	while (c != 'e')
	{
		if (c == 'a')
		{
			Point p;
			p.SetX();
			p.SetY();
			Dots.push_back(p);
		}
		if (c == 'm')
		{
			for (int i = 0; i < Dots.size(); i++)
			{
				M1.push_back(0);
				M2.push_back(0);
			}
			double l1 = -1, l2 = -1;
			for (int i = 0; i < Dots.size(); i++)
			{
				l1 = O1.Dist(Dots[i]);
				l2 = O2.Dist(Dots[i]);
				if (l1 < l2)
				{
					M1[i] = 1;
				}
				else
				{
					M2[i] = 1;
				}
			}
		}
		if (c == 'p')
		{
			std::cout << "Manipulator 1 - ";
			for (int i = 0; i < M1.size(); i++)
			{
				if (M1[i])
				{
					std::cout << " { " << Dots[i].Getx() << " , " << Dots[i].Gety() << " } ";
				}
			}
			std::cout << std::endl;
			std::cout << "Manipulator 2 - ";
			for (int i = 0; i < M2.size(); i++)
			{
				if (M2[i])
				{
					std::cout << " { " << Dots[i].Getx() << " , " << Dots[i].Gety() << " } ";
				}
			}
			std::cout << std::endl;
		}
		std::cout << " --> ";
		std::cin >> c;
	}
}