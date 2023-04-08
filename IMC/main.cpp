#include <iostream>
#include <regex>
#include <string>
#include <memory>

class Imc {
private:
	std::unique_ptr<float> width, height, result, conclusion;

public:
	//Construtor alocando espaço na memoria para os ponteiros declarados acima
	Imc() {
		width = std::make_unique<float>();
		height = std::make_unique<float>();
		result = std::make_unique<float>();
		conclusion = std::make_unique<float>();
	}
	//Construtor alocando espaço na memoria para os ponteiros por parametros
	Imc(float w, float h) {
		width = std::make_unique<float>(w);
		height = std::make_unique<float>(h);
		result = std::make_unique<float>();
		conclusion = std::make_unique<float>();
	}
	~Imc() {}
	//Construtor cópia
	Imc(const Imc& other) {
		width = std::make_unique<float>(*(other.width));
		height = std::make_unique<float>(*(other.height));
		result = std::make_unique<float>(*(other.result));
		conclusion = std::make_unique<float>(*(other.conclusion));
	}

	// Construtor de movimento
	Imc(Imc&& other) noexcept {
		width = std::move(other.width);
		height = std::move(other.height);
		result = std::move(other.result);
		conclusion = std::move(other.conclusion);
	}

	// Operador de atribuição de movimento
	Imc& operator=(Imc&& other) noexcept {
		if (this != &other) {
			width = std::move(other.width);
			height = std::move(other.height);
			result = std::move(other.result);
			conclusion = std::move(other.conclusion);
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
	void showStatus(float im) {
		*conclusion = im;
		 if (*conclusion >= 18 && *conclusion < 25) {
			std::cout << "Saudável ";
}

		else if (*conclusion >= 25 && *conclusion < 30) {
			std::cout << "Peso em excesso ";
}

		else if (*conclusion >= 30 && *conclusion < 35) {
			std::cout << "Obesidade Grau I ";
}

		else if (*conclusion >= 35 && *conclusion < 40) {
			std::cout << "Obesidade Grau II (severa) ";
}

		else {
			std::cout << "Obesidade Grau III";
}
	

	}
};


int main() {
	while (true) {

		//Inicialização do Regex
		std::regex digit_regex("^[0-9.]+$");

		//Criação dos ponteiros
		std::unique_ptr<std::string> input_w;
		std::unique_ptr<std::string> input_h;
		std::unique_ptr<float> heightconv;
		std::unique_ptr<float> widthconv;

		//Alocando memoria dinamica para os ponteiros
		input_w = std::make_unique<std::string>();
		input_h = std::make_unique<std::string>();
		heightconv = std::make_unique<float>();
		widthconv = std::make_unique<float>();

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
				calc.showStatus(calc.showData());
				std::cout << "\n";

				break;
			}
			std::cout << "Entrada invalida. Digite um numero valido.\n";
		}
	}
	return 0;
}