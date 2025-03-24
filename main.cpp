#include <iostream>
#include <cmath>

class ElectricField {
	private:
		double *E;
	public:
		ElectricField()	{
			E = new double[3] {0,0,0};
		}

		ElectricField(double ex, double ey, double ez){
			E = new double[3] {ex,ey, ez};
		}

		double calculate_magnitude(){
			double magnitude = sqrt(E[0] * E[0] + E[1] * E[1] + E[2] * E[2]);
			return magnitude;
		}

		double innerproduct() {
			return E[0] * E[0] + E[1] * E[1] + E[2] *E[2];
			}

		void set_Field(double ex, double ey, double ez) {
			E[0] = ex;
			E[1] = ey;
			E[2] = ez;
		}

		double* get_Field() {
			return E;
		}

		~ElectricField() {
			delete[] E;
		}
};

class MagneticField{
	private:
		double *M;
	public:
		MagneticField() {
			M = new double[3]{0,0,0};

		}
		MagneticField(double mx, double my, double mz) {	
			M = new double[3] {mx, my, mz};
		}

		double calculate_magnitude() {
			double magnitude = sqrt(M[0] * M[0] + M[1] * M[1] + M[2] * M[2]);
			return magnitude;
		}

		void unit_vector(){
			double magnitude = calculate_magnitude();
			double x = M[0] / magnitude;
			double y = M[1] / magnitude;
			double z = M[2] / magnitude;
			std::cout << "(" << x << ", " << y << ", " << z << ")";
		}

		void set_Field(double mx, double my, double mz) {
			M[0] = mx;
			M[1] = my;
			M[2] = mz;
		}

		double* get_Field(){
			return M;
		}

		~MagneticField() {
			delete[] M;
		}
};

int main(){
	ElectricField E_default;
	double* E_values = E_default.get_Field();
	std::cout << "Electric Field(default, before setter): (" << E_values[0] << ", " << E_values[1] << ", " << E_values[2] << ")" << std::endl;
	ElectricField E_components(1e5, 10.9, 1.7e2);
	
	E_default.set_Field(2, 3, 4);
	MagneticField M_default;
	MagneticField M_components(1, 2, 3);




	std::cout << "Electric Field Magnitude (default): " << E_default.calculate_magnitude() << std::endl;
	std::cout << "Electric Field Magnitude (components): " << E_components.calculate_magnitude() << std::endl;
	std::cout << "Electric Field Inner Product (default): " << E_default.innerproduct() << std::endl;
	std::cout << "Electric Field Inner Product (components): " << E_components.innerproduct() << std::endl;
	std::cout << "Magnetic Field Magnitude (components): " << M_components.calculate_magnitude() << std::endl;

	std::cout << "Magnetic Field Unit Vector: ";
	M_components.unit_vector();
	std::cout << std::endl;
	
}





