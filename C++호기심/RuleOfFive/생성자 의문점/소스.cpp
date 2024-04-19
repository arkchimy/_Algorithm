#include <iostream>

using namespace std;

struct Point {
	int x, y;
};

class Polygon {
public:
	Polygon() {
		cout << "기본 생성자 " << endl;
		nPoints = 0;
		points = NULL;
	}
	Polygon(const int nPoints, const Point* points) : nPoints(nPoints) {
		cout << "생성자 오버로딩 구현 " << endl;
		this->points = new Point[nPoints];
		for (int i = 0; i < nPoints; i++)
			this->points[i] = points[i];
	}

	// 복사 생성자 구현
	Polygon(const Polygon& rhs) {
		cout << "복사 생성자 구현" << endl;
		nPoints = rhs.nPoints;
		points = new Point[nPoints];
		for (int i = 0; i < nPoints; i++) {
			points[i] = rhs.points[i];
		}
		//cout << "깊은 복사" << endl;
	}

	// 이동 생성자 구현
	Polygon(Polygon&& rhs) noexcept {
		cout << "이동 생성자 구현" << endl;
		nPoints = rhs.nPoints;
		points = rhs.points;
		rhs.points = NULL;
		//cout << "얕은 복사" << endl;
	}

	~Polygon() {
		delete[] points;
	}

	// 복사 대입 연산자 구현
	Polygon& operator=(const Polygon& rhs) {
		if (this != &rhs) {
			cout << "복사 대입 연산자 구현" << endl;
			nPoints = rhs.nPoints;
			delete[] points;
			points = new Point[nPoints];
			for (int i = 0; i < nPoints; i++) {
				points[i] = rhs.points[i];
			}
		}

		//cout << "깊은 복사" << endl;
		return *this;
	}

	// 이동 대입 연산자 구현
	Polygon& operator=(Polygon&& rhs) {
		if (this != &rhs) {
			cout << "이동 대입 연산자 구현" << endl;
			nPoints = rhs.nPoints;
			delete[] points;
			points = rhs.points;
			rhs.points = NULL;
		}
		//cout << "얕은 복사" << endl;
		return *this;
	}

	int GetNPoints() const {
		return nPoints;
	}

	Point* GetPoints() const {
		if (nPoints == 0) return NULL;
		return points;
	}

private:
	int nPoints;
	Point* points;
};

Polygon getSqare() {

	Point points[4] = { {0, 0}, {1, 0}, {1, 1}, {0, 1} };

	cout << "getSqare()" << endl;
	Polygon p(4, points);

	return p;
}

int main() {


	cout << "========= 1 ============" << endl;
	Polygon a(getSqare());

	cout << "========= 2 ============" << endl;
	a = getSqare();

	cout << "========= 3 ============" << endl;
	Polygon b = a;

	Polygon f(move(b));

	cout << "========= 4 ============" << endl;
	Polygon c(a);

	cout << "========= 5 ============" << endl;
	Polygon d;
	d = a;


	int nPoints = a.GetNPoints();
	Point* points = a.GetPoints();
	for (int i = 0; i < nPoints; i++) {
		cout << "(" << points[i].x << "," << points[i].y << ")" << endl;
	}
}
