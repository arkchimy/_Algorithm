#include <iostream>

using namespace std;

struct Point {
	int x, y;
};

class Polygon {
public:
	Polygon() {
		cout << "�⺻ ������ " << endl;
		nPoints = 0;
		points = NULL;
	}
	Polygon(const int nPoints, const Point* points) : nPoints(nPoints) {
		cout << "������ �����ε� ���� " << endl;
		this->points = new Point[nPoints];
		for (int i = 0; i < nPoints; i++)
			this->points[i] = points[i];
	}

	// ���� ������ ����
	Polygon(const Polygon& rhs) {
		cout << "���� ������ ����" << endl;
		nPoints = rhs.nPoints;
		points = new Point[nPoints];
		for (int i = 0; i < nPoints; i++) {
			points[i] = rhs.points[i];
		}
		//cout << "���� ����" << endl;
	}

	// �̵� ������ ����
	Polygon(Polygon&& rhs) noexcept {
		cout << "�̵� ������ ����" << endl;
		nPoints = rhs.nPoints;
		points = rhs.points;
		rhs.points = NULL;
		//cout << "���� ����" << endl;
	}

	~Polygon() {
		delete[] points;
	}

	// ���� ���� ������ ����
	Polygon& operator=(const Polygon& rhs) {
		if (this != &rhs) {
			cout << "���� ���� ������ ����" << endl;
			nPoints = rhs.nPoints;
			delete[] points;
			points = new Point[nPoints];
			for (int i = 0; i < nPoints; i++) {
				points[i] = rhs.points[i];
			}
		}

		//cout << "���� ����" << endl;
		return *this;
	}

	// �̵� ���� ������ ����
	Polygon& operator=(Polygon&& rhs) {
		if (this != &rhs) {
			cout << "�̵� ���� ������ ����" << endl;
			nPoints = rhs.nPoints;
			delete[] points;
			points = rhs.points;
			rhs.points = NULL;
		}
		//cout << "���� ����" << endl;
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
