#include "shared.h"
#include <iostream>

int main(int argc, const char** argv) {
	/** Creating Locales **/
	Locale americanEnglishLocale({ "en-US", "en_US" });
	std::cout << "American English Locale: " << americanEnglishLocale.getName() << std::endl;

	Locale britishEnglishLocale({ "en-GB", "en_GB" });
	std::cout << "British English Locale: " << britishEnglishLocale.getName() << std::endl;

	Locale germanLocale({ "de-DE", "de_DE" });
	std::cout << "German Locale: " << germanLocale.getName() << std::endl;

	Locale germanMonetaryLocale({ "de-DE", "de_DE" }, LC_MONETARY);
	std::cout << "German [Monetary] Locale: " << germanMonetaryLocale.getName() << std::endl;

	// creating an invalid locale throws an exception
	try {
		Locale invalidLocale("INVALID", LC_ALL, false);
	} catch (Locale::Invalid) {
		std::cout << "Locale invalid" << std::endl;
	}

	// if we specify tryGlobal as true, it will try creating the global locale instead of throwing
	Locale tryGlobalLocale("INVALID", LC_ALL, true);
	std::cout << "Try Global Locale: " << tryGlobalLocale.getName() << std::endl;

	/** Strings To Doubles **/
	std::cout << std::endl;

	// default double conversion behaviour, which consistently expects periods instead of commas
	double resultDouble = 0.0;
	std::cout << "String To Double: " << stringToDouble("1.2345", resultDouble) << "/" << resultDouble << std::endl;

	// here, we create a Locale object without any parameters, so it uses the Global Locale (typically "C")
	std::cout << "String To Double (Global:) " << stringToDouble("1.2345", resultDouble, Locale()) << "/" << resultDouble << std::endl;

	// here, we use the ISO 15897 name "en_AU" to create a Locale object
	std::cout << "String To Double (Australian English - ISO 15897:) " << stringToDouble("1.2345", resultDouble, "en_AU") << "/" << resultDouble << std::endl;

	// here, we use both the IETF and ISO 15897 names "en-CA" and "en_CA" to create a Locale object
	std::cout << "String To Double (Canadian English - IETF/ISO 15897:) " << stringToDouble("1.2345", resultDouble, {"en-CA", "en_CA"}) << "/" << resultDouble << std::endl;
	
	// here, we use the Locale objects we got the names of before
	std::cout << "String To Double (American English:) " << stringToDouble("1.2345", resultDouble, americanEnglishLocale) << "/" << resultDouble << std::endl;
	std::cout << "String To Double (British English:) " << stringToDouble("1.2345", resultDouble, britishEnglishLocale) << "/" << resultDouble << std::endl;
	
	// for this conversion, the string has a comma instead of a period
	std::cout << "String To Double (German:) " << stringToDouble("1,2345", resultDouble, germanLocale) << "/" << resultDouble << std::endl;

	// for this conversion, the string has a period instead of a comma, because this German Locale is for the Monetary LC only
	std::cout << "String To Double (German [Monetary:]) " << stringToDouble("1.2345", resultDouble, germanMonetaryLocale) << "/" << resultDouble << std::endl;

	/** Strings To Numbers **/
	std::cout << std::endl;

	// default float conversion behaviour, which consistently expects periods instead of commas
	float resultFloat = 0.0f;
	std::cout << "String To Float: " << stringToFloat("1.2345", resultFloat) << "/" << resultFloat << std::endl;

	long resultLong = 0;
	std::cout << "String To Long: " << stringToLong("-12345", resultLong) << "/" << resultLong << std::endl;

	unsigned long resultLongUnsigned = 0;
	std::cout << "String To Long (Unsigned:) " << stringToLongUnsigned("12345", resultLongUnsigned) << "/" << resultLongUnsigned << std::endl;
	return 0;
}