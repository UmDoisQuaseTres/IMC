#include <iostream>
#include <regex>
#include <string>


class Imc {
private:
	float *width = nullptr, *height = nullptr, *result = nullptr;

public:
	//Construtor alocando espaço na memoria para os ponteiros declarados acima
	Imc() {
		width = new float;
		height = new float;
		result = new float;
	}
	//Construtor alocando espaço na memoria para os ponteiros por parametros
	Imc(float w, float h) { 
		width = new float(w);
		height = new float(h);
		result = new float;
	}
	//Construtor cópia
	Imc(const Imc& other) {
		width = new float(*(other.width));
		height = new float(*(other.height));
		result = new float(*(other.result));
	}
	//Definindo operador de atribuição
	Imc& operator=(const Imc& other) {
		if (this != &other) {
			*width = *(other.width);
			*height = *(other.height);
			*result = *(other.result);
		}
		return *this;
	}

	void setW(float w) {
		*width = w;
	}
	void SetH(float h) {
		*height = h;
	}
	void calcData() {
		*result = (*height) / ((*width) * (*width));
	}
	float showData() {
		return *result;
	}

};


int main() {
	while (true) {

		//Inicialização do Regex
		std::regex digit_regex("^[0-9.]+$");

		//Criação dos ponteiros
		std::string* input_w = nullptr;
		std::string *input_h = nullptr;
		float* heightconv = nullptr;
		float *widthconv = nullptr;

		//Alocando memoria dinamica para os ponteiros
		input_w = new std::string;
		input_h = new std::string;
		heightconv = new float;
		widthconv = new float;

		Imc calc{};


		while (true) {
			std::cout << "Digite seu peso em kilos por favor: \n";
			std::getline(std::cin, *input_h);

			if (std::regex_match(*input_h, digit_regex)) {
				*heightconv = std::stof(*input_h);
				calc.SetH(*heightconv);
				std::cin.clear();
				break;
			}
			std::cout << "Entrada invalida. Digite um numero valido.\n";
		}
		


		while (true) {
			std::cout << "Digite sua altura por favor: \n";
			std::getline(std::cin, *input_w);
			if (std::regex_match(*input_w, digit_regex)) {
				*widthconv = std::stof(*input_w);
				calc.setW(*widthconv);
				std::cin.clear();
				calc.calcData();
				std::cout << calc.showData() << "\n";
				break;
			}
			std::cout << "Entrada invalida. Digite um numero valido.\n";
		}
	
		delete input_w;
		delete input_h;
		delete heightconv;
		delete widthconv;
		

	}
	return 0;
}