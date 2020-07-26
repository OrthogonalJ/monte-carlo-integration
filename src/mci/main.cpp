#include <cstddef>
#include <iostream>
#include <cmath>
#include <string>
#include <functional>

#include "mci/monte_carlo_integration.h"
#include "mci/numeric_types.h"

void show_integration(
		std::string description, 
		const std::function<mci::RealType(const mci::RealType&)>& base_function,
		std::size_t num_samples, 
		mci::RealType lower_bound, 
		mci::RealType upper_bound) {
	std::cout << "Integrating " << description << " over [" << lower_bound << ", " << upper_bound << "]" <<
			" using " << num_samples << " samples." << std::endl;
	const mci::RealType integral = mci::monte_carlo_integral(base_function, num_samples, lower_bound, upper_bound);
	std::cout << "Value: " << integral << std::endl;
}

int main(int argv, char** argc) {
	const std::size_t num_samples = 1e+7;
	
	show_integration(
		"Exp[-(x^2)]",
		[](const mci::RealType& x) {
			return std::exp(-std::pow(x, 2.0));
		}, 
		num_samples, mci::REAL_NEGATIVE_INFINITY, mci::REAL_INFINITY
	);
	
	show_integration(
		"Exp[-(x^2)]",
		[](const mci::RealType& x) {
			return std::exp(-std::pow(x, 2.0));
		}, 
		num_samples, 4.0, mci::REAL_INFINITY
	);
	
	show_integration(
		"Exp[-(x^2)]",
		[](const mci::RealType& x) {
			return std::exp(-std::pow(x, 2.0));
		}, 
		num_samples, mci::REAL_NEGATIVE_INFINITY, -2.0
	);
	
	show_integration(
		"Exp[-(x^2)]",
		[](const mci::RealType& x) {
			return std::exp(-std::pow(x, 2.0));
		}, 
		num_samples, 3.0, 4.0
	);
}