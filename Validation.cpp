// Validation.cpp - IsValid() function implementation
// Written by Sam Springer

#include <string>
#include <iostream>

using namespace std;

// Define constants
#define MAX_EMAIL_SIZE 255 // Just a constant, do not need equals or semicolon
#define VALID_LOCALPART_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789._-"
#define VALID_SUBDOMAINPART_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789.-"
#define MAX_LOCALNAME_SIZE 64
#define VALID_TOP_LEVEL_DOMAINS ["com", "net", "org", "mil"] // Check this part out, not sure if it is valid

// Function Prototypes
bool DotDashRules(const string& emailAddress);

// Email validation function
bool IsValid(const string& emailAddress)
{
	// 1. Check emailAddress size, use length operation
	if (emailAddress.length() > MAX_EMAIL_SIZE)
		return false;

	// 2. Find '@' symbol
	int atPosition = emailAddress.find('@');
	if (atPosition == string::npos) // means @ character not found
		return false;

	// 3. Extract localPart and domain
	string localPart, domain;

	localPart = emailAddress.substr(0, atPosition);
	domain = emailAddress.substr(atPosition + 1);

	// CHECK localPart
	// 4. Check localPart size
	if (localPart.length() > 64 || localPart.length() == 0)
		return false;

	// 5. Check localPart for valid characters
	if (localPart.find_first_not_of(VALID_LOCALPART_CHARS) != string::npos)
		return false;

	// 6. Check localPart for '.' and '-' rules
	if (DotDashRules(emailAddress) == false) // Better way to do this
		return false;

	// CHECK domain
	// 7. Check domain size
	if (domain.length() > 255 || domain.length() == 0)
		return false;

	// 8. Find '.' starting from the end
	int lastDot = domain.rfind(".");

	// 9. Extract TLD
	string topLevelDomain;
	if (lastDot != string::npos)
		topLevelDomain = domain.substr(lastDot + 1);
	else
		return false;

	// 10. Validate TLD
	
	// 11. Extract subdomain
	string subdomain = domain.substr(0, lastDot);

	// 12. Check subdomain for valid characters
	if (localPart.find_first_not_of(VALID_SUBDOMAINPART_CHARS) != string::npos)
		return false;

	// 13. Check subdomain for '.' and '-' rules
	 if (DotDashRules(emailAddress) == false) // better way to do this
		 return false;

	return true;
}

// Check the address for violations of the dot and dash rule
bool DotDashRules(const string& emailAddress)
{
	// Locate locations of any violations
	int doubleDot = emailAddress.find("..");
	int doubleDash = emailAddress.find("--");
	int dotDash = emailAddress.find(".-");
	int dashDot = emailAddress.find("-.");

	// If any violations are found, the email is invalid
	if (doubleDot != string::npos || doubleDash != string::npos || dotDash != string::npos || dashDot != string::npos)
		return false;
	
	// Check if the address begins with a dash or a period, NOT WORKING
	if (emailAddress.substr(0, 0) == "." || emailAddress.substr(0, 0) == "-")
		return false;

	//Check if the address ends with a dash or period
}