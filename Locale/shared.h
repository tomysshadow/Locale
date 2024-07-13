#pragma once
#define _WIN32_WINNT 0x0500
#include "scope_guard.hpp"
#include "Locale.h"
#include <stdexcept>
#include <string.h>
#include <windows.h>

// tries to ensure consistent interpretation of periods and commas in string to number conversions
// first tries the IETF locale "en-US", then the language[_country-region[.code-page]] locale "en_US"
// then tries the global locale (typically "C") if neither are available
static const Locale STRING_TO_NUMBER_LOCALE_DEFAULT({"en-US", "en_US"}, LC_NUMERIC, true);

inline size_t stringToDouble(const char* str, double &result, const Locale &locale = STRING_TO_NUMBER_LOCALE_DEFAULT) {
	MAKE_SCOPE_EXIT(resultScopeExit) {
		result = 0.0;
	};

	if (!str) {
		return 0;
	}

	char* endPointer = 0;

	errno = 0;
	result = _strtod_l(str, &endPointer, locale);
	size_t size = (result || !errno) ? (size_t)(endPointer - str) : 0;

	resultScopeExit.dismiss();
	return size;
}

inline size_t stringToDoubleWide(const wchar_t* str, double &result, const Locale &locale = STRING_TO_NUMBER_LOCALE_DEFAULT) {
	MAKE_SCOPE_EXIT(resultScopeExit) {
		result = 0.0;
	};

	if (!str) {
		return 0;
	}

	wchar_t* endPointer = 0;

	errno = 0;
	result = _wcstod_l(str, &endPointer, locale);
	size_t size = (result || !errno) ? (size_t)(endPointer - str) : 0;

	resultScopeExit.dismiss();
	return size;
}

inline double stringToDoubleOrDefaultValue(const char* str, double defaultValue = 0.0, const Locale &locale = STRING_TO_NUMBER_LOCALE_DEFAULT) {
	double result = 0.0;
	return stringToDouble(str, result, locale) ? result : defaultValue;
}

inline double stringToDoubleOrDefaultValueWide(const wchar_t* str, double defaultValue = 0.0, const Locale &locale = STRING_TO_NUMBER_LOCALE_DEFAULT) {
	double result = 0.0;
	return stringToDoubleWide(str, result, locale) ? result : defaultValue;
}

inline size_t stringToFloat(const char* str, float &result, const Locale &locale = STRING_TO_NUMBER_LOCALE_DEFAULT) {
	MAKE_SCOPE_EXIT(resultScopeExit) {
		result = 0.0f;
	};

	if (!str) {
		return 0;
	}

	char* endPointer = 0;

	errno = 0;
	result = _strtof_l(str, &endPointer, locale);
	size_t size = (result || !errno) ? (size_t)(endPointer - str) : 0;

	resultScopeExit.dismiss();
	return size;
}

inline size_t stringToFloatWide(const wchar_t* str, float &result, const Locale &locale = STRING_TO_NUMBER_LOCALE_DEFAULT) {
	MAKE_SCOPE_EXIT(resultScopeExit) {
		result = 0.0f;
	};

	if (!str) {
		return 0;
	}

	wchar_t* endPointer = 0;

	errno = 0;
	result = _wcstof_l(str, &endPointer, locale);
	size_t size = (result || !errno) ? (size_t)(endPointer - str) : 0;

	resultScopeExit.dismiss();
	return size;
}

inline float stringToFloatOrDefaultValue(const char* str, float defaultValue = 0.0f, const Locale &locale = STRING_TO_NUMBER_LOCALE_DEFAULT) {
	float result = 0.0f;
	return stringToFloat(str, result, locale) ? result : defaultValue;
}

inline float stringToFloatOrDefaultValueWide(const wchar_t* str, float defaultValue = 0.0f, const Locale &locale = STRING_TO_NUMBER_LOCALE_DEFAULT) {
	float result = 0.0f;
	return stringToFloatWide(str, result, locale) ? result : defaultValue;
}

inline size_t stringToLong(const char* str, long &result, int base = 0, const Locale &locale = STRING_TO_NUMBER_LOCALE_DEFAULT) {
	MAKE_SCOPE_EXIT(resultScopeExit) {
		result = 0;
	};

	if (!str) {
		return 0;
	}

	char* endPointer = 0;

	errno = 0;
	result = _strtol_l(str, &endPointer, base, locale);
	size_t size = (result || !errno) ? (size_t)(endPointer - str) : 0;

	resultScopeExit.dismiss();
	return size;
}

inline size_t stringToLongWide(const wchar_t* str, long &result, int base = 0, const Locale &locale = STRING_TO_NUMBER_LOCALE_DEFAULT) {
	MAKE_SCOPE_EXIT(resultScopeExit) {
		result = 0;
	};

	if (!str) {
		return 0;
	}

	wchar_t* endPointer = 0;

	errno = 0;
	result = _wcstol_l(str, &endPointer, base, locale);
	size_t size = (result || !errno) ? (size_t)(endPointer - str) : 0;

	resultScopeExit.dismiss();
	return size;
}

inline long stringToLongOrDefaultValue(const char* str, long defaultValue = 0, int base = 0, const Locale &locale = STRING_TO_NUMBER_LOCALE_DEFAULT) {
	long result = 0;
	return stringToLong(str, result, base, locale) ? result : defaultValue;
}

inline long stringToLongOrDefaultValueWide(const wchar_t* str, long defaultValue = 0, int base = 0, const Locale &locale = STRING_TO_NUMBER_LOCALE_DEFAULT) {
	long result = 0;
	return stringToLongWide(str, result, base, locale) ? result : defaultValue;
}

inline size_t stringToLongUnsigned(const char* str, unsigned long &result, int base = 0, const Locale &locale = STRING_TO_NUMBER_LOCALE_DEFAULT) {
	MAKE_SCOPE_EXIT(resultScopeExit) {
		result = 0;
	};

	if (!str) {
		return 0;
	}

	char* endPointer = 0;

	errno = 0;
	result = _strtoul_l(str, &endPointer, base, locale);
	size_t size = (result || !errno) ? (size_t)(endPointer - str) : 0;

	resultScopeExit.dismiss();
	return size;
}

inline size_t stringToLongUnsignedWide(const wchar_t* str, unsigned long &result, int base = 0, const Locale &locale = STRING_TO_NUMBER_LOCALE_DEFAULT) {
	MAKE_SCOPE_EXIT(resultScopeExit) {
		result = 0;
	};

	if (!str) {
		return 0;
	}

	wchar_t* endPointer = 0;

	errno = 0;
	result = _wcstoul_l(str, &endPointer, base, locale);
	size_t size = (result || !errno) ? (size_t)(endPointer - str) : 0;

	resultScopeExit.dismiss();
	return size;
}

inline long stringToLongUnsignedOrDefaultValue(const char* str, unsigned long defaultValue = 0, int base = 0, const Locale &locale = STRING_TO_NUMBER_LOCALE_DEFAULT) {
	unsigned long result = 0;
	return stringToLongUnsigned(str, result, base, locale) ? result : defaultValue;
}

inline long stringToLongUnsignedOrDefaultValueWide(const wchar_t* str, unsigned long defaultValue = 0, int base = 0, const Locale &locale = STRING_TO_NUMBER_LOCALE_DEFAULT) {
	unsigned long result = 0;
	return stringToLongUnsignedWide(str, result, base, locale) ? result : defaultValue;
}