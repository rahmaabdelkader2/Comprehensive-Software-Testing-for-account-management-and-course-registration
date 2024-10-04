#include "Tests.h"

/* Test Code to test the Sign Up */
static struct User_Input_Type Test1_User =
{
	{
	-1, // this is to indecate user hasn't assigned ID 
	"Ahmed",
	26,
	23,
	10,
	1998,
	Male,
	Masters_Student
	},
	{
		{
			"EdgesAcademy",
			"Edges123"
		},
	"Edges123"
	}
};

/* Test Code to test the Sign Up */
static struct User_Input_Type Test2_User =
{
	{
	-1, // this is to indecate user hasn't assigned ID 
	"Rania",
	54,
	31,
	12,
	1970,
	Female,
	PHD_Holder
	},
	{
		{
			"EdgesAcademy2024",
			"Edges_123_"
		},
	"Edges_123_$$"
	}
};

/* Test Code to test the Sign Up */
static struct User_Input_Type Test3_User =
{
	{
	-1, // this is to indecate user hasn't assigned ID 
	"rahma",
	22,
	24,
	2,
	2002,
	Female,
	9
	},
	{
		{
			"rahmaaaaaaaa",
			"rahmaaaa11"
		},
			"rahmaaaa11"
	}
};

// Step 1: Add a test user
struct User_Input_Type Test4_User = {
	{
	-1, // this is to indecate user hasn't assigned ID 
	"rahma",
	22,
	24,
	2,
	2002,
	Female,
	Graduate
	},
	{
		{
			"rahmaaaaaaaa",
			"rahmaaaa11"
		},
			"rahmaaaa11"
	}
};

/* init function for Test Suite 1*/
static unsigned char test1_start(void)
{
	unsigned char RET = Add_Account(&Test1_User);
	Test1_User.PersonalInfo_Form.id = current_user_test - 1;
	DBM_PrintUsers();
	return !RET;
}

/* Closure Function For Test Suite 1*/
static unsigned char test1_end(void)
{
	unsigned char RET = Delete_Account(current_user_test - 1);
	DBM_PrintUsers();
	return !RET;
}

/* init function for Test Suite 2*/
static unsigned char test2_start(void)
{
	unsigned char RET = Add_Account(&Test2_User);
	Test2_User.PersonalInfo_Form.id = current_user_test - 1;
	DBM_PrintUsers();
	return !RET;
}

/* Closure Function For Test Suite 2*/
static unsigned char test2_end(void)
{
	unsigned char RET = Delete_Account(current_user_test - 1);
	DBM_PrintUsers();
	return !RET;
}

/* init function for Test Suite 2*/
static unsigned char test3_start(void)
{
	unsigned char RET = Add_Account(&Test3_User);
	Test3_User.PersonalInfo_Form.id = current_user_test - 1;
	DBM_PrintUsers();
	return !RET;
}

/* Closure Function For Test Suite 3*/
static unsigned char test3_end(void)
{
	unsigned char RET = Delete_Account(current_user_test - 1);
	DBM_PrintUsers();
	return !RET;
}

/* init function for Test Suite 43*/
static unsigned char test43_start(void)
{
	unsigned char RET = Add_Account(&Test4_User);
	Test4_User.PersonalInfo_Form.id = current_user_test - 1;
	DBM_PrintUsers();
	if (RET == 1) {
		printf("User 'TestUser' added successfully.\n");
	}
	else {
		printf("Failed to add user 'TestUser'.\n");
	}

	return !RET;
}

/* Closure Function For Test Suite 43*/
static unsigned char test43_end(void)
{
	unsigned char RET = Delete_Account(current_user_test - 1);
	DBM_PrintUsers();
	if (RET == 1) {
		printf("User 'TestUser' deleted successfully.\n");
	}
	else {
		printf("User 'TestUser' deletion failed or was already deleted.\n");
	}
	return !RET;
}


/* Start function for TestCase_DBM_PrintUserData_Admin */
static unsigned char test46_start(void)
{
	
	
	//  Add the user to the database
	unsigned char result = Add_Account(&Test4_User);

	// Store the ID of the test user globally for later use in the test
	Test4_User.PersonalInfo_Form.id = current_user_test - 1;

	// Check if the user was added successfully
	if (result == 1) {
		printf("Test setup: User  added successfully with ID %d.\n", Test4_User.PersonalInfo_Form.id);
		return 0;
	}
	else {
		printf("Test setup: Failed to add \n");
		return 1; 
	}
}

/* End function for TestCase_DBM_PrintUserData_Admin */
static unsigned char test46_end(void)
{
	// Step 1: Delete the test user created in the start function
	unsigned int test_user_id = current_user_test - 1; // Get the ID of the user added during the start function
	unsigned char delete_result = Delete_Account(test_user_id);

	// Check if the user was deleted successfully
	if (delete_result == 1) {
		printf("Test cleanup: User 'John Doe' deleted successfully.\n");
		return 0; // 0 means success in CUnit's end function
	}
	else {
		printf("Test cleanup: Failed to delete test user 'John Doe'.\n");
		return 1; // 1 means failure in CUnit's end function
	}
}

/* Start function for DBM_PrintUsers test */
static unsigned char test47_start(void)
{


	// Step 2: Add the users to the database
	unsigned char result1 = Add_Account(&Test1_User);
	//unsigned char result2 = Add_Account(&Test2_User);
	unsigned char result2 = Add_Account(&Test4_User);

	// Step 3: Verify that all users were added successfully
	if (result1 == 1 && result2 == 1) {
		printf("Test setup: All users added successfully.\n");
		return 0;  // 0 means success in CUnit's start function
	}
	else {
		printf("Test setup: Failed to add users.\n");
		return 1;  // 1 means failure in CUnit's start function
	}
}

/* End function for DBM_PrintUsers test */
static unsigned char test47_end(void)
{
	
	unsigned int user1_id = current_user_test - 3;
	unsigned int user2_id = current_user_test - 2;
	

	
	unsigned char delete_result1 = Delete_Account(user1_id);
	unsigned char delete_result2 = Delete_Account(user2_id);


	
	if (delete_result1 == 1 && delete_result2 == 1) {
		printf("Test cleanup: All users deleted successfully.\n");
		return 0;  // 0 means success in CUnit's end function
	}
	else {
		printf("Test cleanup: Failed to delete some users.\n");
		return 1;  // 1 means failure in CUnit's end function
	}
}

// Start function for TestCase48
static unsigned char TestCase48_start(void)
{
	// Add the user to the database
	unsigned char result = Add_Account(&Test4_User);
	Test4_User.PersonalInfo_Form.id = current_user_test - 1;

	// Check if the user was added successfully
	if (result == 1) {
		printf("added successfully.\n");
		return 0; // Return 0 for success
	}
	else {
		printf("Failed to add.\n");
		return 1; // Return 1 for failure
	}
}

// End function for TestCase48
static unsigned char TestCase48_end(void)
{
	// Track the user ID of the user created in the start function
	unsigned int test_customer_id = current_user_test - 1;

	// Delete the test customer account
	unsigned char delete_result = Delete_Account(test_customer_id);

	// Check if the user was deleted successfully
	if (delete_result == 1) {
		printf("deleted successfully.\n");
		return 0; // Return 0 for success
	}
	else {
		printf("Failed to delete.\n");
		return 1; // Return 1 for failure
	}
}

// Start function for TestCase57
static unsigned char TestCase57_start(void)
{
	static unsigned int Session_User_id = 1; // Assuming user 1 is logged in
	int Course_id = 1; // Assuming this is a valid course ID

	// Directly enroll the user in the course
	// Simulate the condition that the user is already enrolled
	AddStudentToCourse(Course_id, Session_User_id); // Assume this enrolls the user

	// Attempt to add the student to the same course again
	int RET = AddStudentToCourse(Course_id, Session_User_id);

	// Check for expected return value indicating already enrolled
	CU_ASSERT_EQUAL(RET, AlreadyEnrolled);

	// Confirm that the correct message is printed
	printf("You Are Already Enrolled to this Course \n"); // Expected output
	
}

/************************************************************************************
* Test ID                : TestCase 1
* Description            : Testing the Add Account Functionality
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Ahmed
*                          Age                          -> 26
*                          DOB_day                      -> 01
*                          DOB_Month                    -> 02
*                          DOB_Year                     -> 1999
*                          Educational_Status           -> Masters_Student
*                          Gender                       -> Male
*                          UserName                     -> EdgesAcademy
*                          Password                     -> Edges123
*                          Password Recheck             -> Edges123
* Test Expected output   : The DB should be updated with the previous inputs correctly
* Reason                 : All inputs are in correct format
*************************************************************************************/
static void TestCase1(void)
{
	unsigned int Test_id = Test1_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test1_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test1_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test1_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test1_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test1_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test1_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test1_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test1_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test1_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test1_User.PersonalInfo_Form.id);
}

/************************************************************************************
* Test ID                : TestCase 2
* Description            : Testing the Add Account Functionality
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 31
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> Female
*                          UserName                     -> EdgesAcademy2024
*                          Password                     -> Edges_123_$$
*                          Password Recheck             -> Edges123
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : Password inputs mismatch so the suite willn't initiallize
*************************************************************************************/
static void TestCase2(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}
/************************************************************************************
** Equivelanvce partition Tests + Boundary value analysis Tests + Pairwise testing **
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 1
* Description            : Testing the Add Account Functionality handling missing info (Name)
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> 0
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2024
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : the name is not provided
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 2
* Description            : Testing the Add Account Functionality with invalid char in name
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> @#rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : Why accepting special characters in the name field?
* Bug                    : Yes
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 3
* Description            : Testing the Add Account Functionality with handling numbers in name field 
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> 123
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : Why accepting special characters in the name field?
* Bug                    : Yes
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 4
* Description            : Testing the Add Account Functionality handling missing age
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 0
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2024
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : the age field accepts zero when the year provided is correct with it as a calculation (current year(2024) -2024 )
* Bug                    : Yes
*************************************************************************************/
/************************************************************************************
* Test ID                : TestCase 5
* Description            : Testing the Add Account Functionality handling negative values in age
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> -1
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2025
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : the age field doesn't accept negative even if  the year provided is correct with it as a calculation (current year(2024) -2025 )
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 6
* Description            : Testing the Add Account Functionality handling the right DOB_day (missing)
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 0
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : number of days must be in range of (1-31)
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 7
* Description            : Testing the Add Account Functionality handling the right DOB_day
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 1
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB should be updated with the previous inputs
* Reason                 : right value is entered
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 8
* Description            : Testing the Add Account Functionality handling the right DOB_day
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 15
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB should be updated with the previous inputs
* Reason                 : right value is enetered
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 9
* Description            : Testing the Add Account Functionality handling the right DOB_day
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 31
*                          DOB_Month                    -> 1
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB should be updated with the previous inputs
* Reason                 : right value is entered
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 10
* Description            : Testing the Add Account Functionality handling the right DOB_day
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 32
*                          DOB_Month                    -> 1
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : wrong value is entered ( 1-31 )
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 11
* Description            : Testing the Add Account Functionality handling the right DOB_Month
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 12
*                          DOB_Month                    -> 0
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : month range should be within (1-12)
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 12
* Description            : Testing the Add Account Functionality handling the right DOB_Month
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 12
*                          DOB_Month                    -> 1
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB should be updated with the previous inputs
* Reason                 : value enetered is correct
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 13
* Description            : Testing the Add Account Functionality handling the right DOB_Month
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 12
*                          DOB_Month                    -> 7
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB should be updated with the previous inputs
* Reason                 : value enetered is correct
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 14
* Description            : Testing the Add Account Functionality handling the right DOB_Month
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 12
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB should be updated with the previous inputs
* Reason                 : value enetered is correct
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 15
* Description            : Testing the Add Account Functionality handling the right DOB_Month
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 12
*                          DOB_Month                    -> 13
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : value enetered is not wihtin the range (1-12)
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 16
* Description            : Testing the Add Account Functionality handling the right days number within each months
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 29
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : the DOB_day is not right for february (1-28) for non-leap years
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 17
* Description            : Testing the Add Account Functionality handling the right days number within each months
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 31
*                          DOB_Month                    -> 3
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB should be updated with the previous inputs
* Reason                 : the DOB_day is right for march as it's from 1-31
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 18
* Description            : Testing the Add Account Functionality handling the right value for years
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 3
*                          DOB_Year                     -> 0
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : the DOB_year is not missing
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 19
* Description            : Testing the Add Account Functionality handling the calculation of age according to year provided
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 19
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : the DOB is not correct with the age provided
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 20
* Description            : Testing the Add Account Functionality handling the calculation of age according to year provided
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB should be updated with the previous inputs
* Reason                 : the DOB_year is correct with the age provided
* Bug                    : No
*************************************************************************************/


/************************************************************************************
* Test ID                : TestCase 21
* Description            : Testing the Add Account Functionality invalid educational status
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> 0
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : incorrect value for educational status
* Bug                    : no
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 22
* Description            : Testing the Add Account Functionality invalid educational status
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> 1
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB should be updated with the previous inputs
* Reason                 : valid value for educational status
* Bug                    : no
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 23
* Description            : Testing the Add Account Functionality invalid educational status
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB should be updated with the previous inputs
* Reason                 : correct value for educational status as it's defined as 3 in the system
* Bug                    : no
*************************************************************************************/


/************************************************************************************
* Test ID                : TestCase 24
* Description            : Testing the Add Account Functionality invalid educational status
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> 10
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : incorrect value for educational status
* Bug                    : no
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 25
* Description            : Testing the Add Account Functionality invalid educational status
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> PHD_Student
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB should be updated with the previous inputs
* Reason                 : incorrect educational status are saved (PHD_Student ==> thrusday)
* Bug                    : Yes
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 26
* Description            : Testing the Add Account Functionality handling the right age for eachtegory: graduate,ph holder,masters,..etc
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 15
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2009
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : the educational status doesn't match with the age provided
* Bug/Not                : Yes
*************************************************************************************/


/************************************************************************************
* Test ID                : TestCase 27
* Description            : Testing the Add Account Functionality handling missing info (gender)
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> 0
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : the gender is not provided
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 28
* Description            : Testing the Add Account Functionality handling wrong info (gender)
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Others
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : the gender is wrong , it's either female or male
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 29
* Description            : Testing the Add Account Functionality handling wrong info (gender)
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> 3
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : the gender must be 1 or 2 male or female
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 30
* Description            : Testing the Add Account Functionality handling (gender)
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> 2
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB should be updated with the previous inputs
* Reason                 : the gender 2 means female then it's true
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 31
* Description            : Testing the Add Account Functionality handling (gender)
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB should be updated with the previous inputs
* Reason                 : the gender is valid
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 32
* Description            : Testing the Add Account Functionality within 7 char in username
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaab
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : invalid number of char
* Bug                    : No
*************************************************************************************/


/************************************************************************************
* Test ID                : TestCase 33
* Description            : Testing the Add Account Functionality within 8 char in username
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaabd
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB should be updated with the previous inputs
* Reason                 : valid number of char
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 34
* Description            : Testing the Add Account Functionality within 32 char in username (valid range)
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaaaaaaaaaaaaaaaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB should be updated with the previous inputs
* Reason                 : the boundry condition isn't handled ( suppose 8-32 )
* Bug                    : Yes
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 35
* Description            : Testing the Add Account Functionality handling more than 32 char in username (33)
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : more than 32 char in username is not allowed
* Bug                    : No
*************************************************************************************/


/************************************************************************************
* Test ID                : TestCase 36
* Description            : Testing the Add Account Functionality handling duplicated usernames
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> AdminUser1
*                          Password                     -> Edges123
*                          Password Recheck             -> Edges123
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : the username is duplicated ( already present in the database )
* Bug                    : Yes
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 37
* Description            : Testing the Add Account Functionality invalid char or numbers in username
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> $%@$1aaa
*                          Password                     -> rahmaaaa11
*                          Password Recheck             -> rahmaaaa11
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : special characters are not accepted in the isername
* Bug                    : Yes
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 38
* Description            : Testing the Add Account Functionality within 7 char in pass (invalid range)
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaa
*                          Password Recheck             -> rahmaaa
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : less than 8 char is not allowed
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 39
* Description            : Testing the Add Account Functionality within 8 char in pass (valid range)
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa
*                          Password Recheck             -> rahmaaaa
* Test Expected output   : The DB should be updated with the previous inputs
* Reason                 : correct number of char within the right range
* Bug                    : No
*************************************************************************************/


/************************************************************************************
* Test ID                : TestCase 40
* Description            : Testing the Add Account Functionality within 32 char in pass (valid range)
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa111111111111111111111111
*                          Password Recheck             -> rahmaaaa111111111111111111111111
* Test Expected output   : The DB should be updated with the previous inputs
* Reason                 : the boundry condition is within the right range
* Bug                    : Yes
*************************************************************************************/


/************************************************************************************
* Test ID                : TestCase 41
* Description            : Testing the Add Account Functionality within 30 char in pass (valid range)
* Pre-requisits          : DB initaialized
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa1111111111111111111111
*                          Password Recheck             -> rahmaaaa1111111111111111111111
* Test Expected output   : The DB should be updated with the previous inputs
* Reason                 : the boundry condition is within the right range
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase 42
* Description            : Testing the Add Account Functionality handling more than 32 char in password
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> rahma
*                          Age                          -> 22
*                          DOB_day                      -> 24
*                          DOB_Month                    -> 2
*                          DOB_Year                     -> 2002
*                          Educational_Status           -> Graduate
*                          Gender                       -> Female
*                          UserName                     -> rahmaaaaaaaa
*                          Password                     -> rahmaaaa1111111111111111111111111111111111111111111111111111
*                          Password Recheck             -> rahmaaaa1111111111111111111111111111111111111111111111111111
* Test Expected output   : The DB should be updated with the previous inputs
* Reason                 : The DB shouldn't be updated with the previous inputs
* Bug                    : No
*************************************************************************************/


static void TestCase3(void)
{
	unsigned int Test_id = Test3_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test3_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test3_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test3_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test3_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test3_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test3_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test3_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test3_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test3_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test3_User.PersonalInfo_Form.id);
}

/************************************************************************************
* Test ID                : TestCase43
* Description            : Add an account, delete it, and then verify it is deleted.
* Pre-requisites         : None
* Test Expected output   : The account should be added, deleted, and then confirmed to be removed from the database.
* Bug                    : No
*************************************************************************************/

/* Function to check if an account is deleted */
unsigned char Is_Account_Deleted(unsigned short user_id)
{

	if (DB_info[user_id].id == -1) {
		
		return 1;  
	}

	
	return 0;  
}

static void TestCase43(void)
{

	// Delete the account
	unsigned char delete_result = Delete_Account(Test4_User.PersonalInfo_Form.id);

	// Verify that the account was successfully deleted
	CU_ASSERT_EQUAL(delete_result, 1);  

	// Check if the account is deleted
	unsigned char deletion_check = Is_Account_Deleted(Test4_User.PersonalInfo_Form.id);

	// Verify that the account no longer exists in the database
	CU_ASSERT_EQUAL(deletion_check, 1);  
}


/************************************************************************************
* Test ID                : TestCase44
* Description            : Test the AddStudentToCourse functionality for enrollment.
* Pre-requisites         : A valid student and a valid course (Course 1) exist or not
* Test Expected output   : The student should be enrolled successfully and return "Already Enrolled" if tried again.
*************************************************************************************/
static void TestCase44(void)
{
	unsigned int student_id = 1; 
	unsigned int course_id = 1;  // Standard_Diploma 

	// Enrolling the student into the course for the first time
	unsigned char result = AddStudentToCourse(course_id, student_id);
	CU_ASSERT_EQUAL(result, Enrolled); 

	// Enrolling the same student into the course again
	result = AddStudentToCourse(course_id, student_id);
	CU_ASSERT_EQUAL(result, AlreadyEnrolled); 
}

/************************************************************************************
* Test ID                : TestCase45
* Description            : Test the AddStudentToCourse functionality when the course is full. (more than 5 students)
* Pre-requisites         : Course 5 (Testing_Diploma) is includes  3 enrolled students.
* Test Expected output   : The function should return "Capacity Completed" when attempting to enroll a student.
* Bug                    : Yes
*************************************************************************************/
static void TestCase45(void)
{
	unsigned int student_id = 6; // max number enrolled is 5 
	unsigned int course_id = 1;        

	// enroll another student in a course that is at full capacity
	unsigned char result = AddStudentToCourse(course_id, student_id);
	CU_ASSERT_EQUAL(result, CapacityCompleted); 
}
/************************************************************************************
* Test ID                : TestCase46
* Description            : Test the DBM_PrintUserData_Admin function for valid and invalid user IDs.
* Pre-requisites         : A user is added to the system.
* Test Expected output   : The function should print the correct user data for valid user IDs and handle invalid IDs properly.
*************************************************************************************/
static void TestCase46(void)
{

	unsigned int test_user_id = current_user_test - 1; 

	
	unsigned char print_result = DBM_PrintUserData_Admin(test_user_id);
	CU_ASSERT_EQUAL(print_result, TRUE);  

	
	unsigned char invalid_print_result = DBM_PrintUserData_Admin(MAX_USERS + 1);  // Using an invalid ID
	CU_ASSERT_EQUAL(invalid_print_result, FALSE);  
}

/************************************************************************************
* Test ID                : TestCase47
* Description            : Test the DBM_PrintUsers function which prints all user data.
* Pre-requisites         : Multiple users are added to the system.
* Test Expected output   : All users in the system should be printed
* Bug                    : yes ( the function print all the users and all the unsigned ones are set to default 
*                          so it always print 5 users even if they are not all registered ( printing till max user not the current user -1)
*************************************************************************************/
static void TestCase47(void)
{
	DBM_PrintUsers();

}


/************************************************************************************
* Test ID                : TestCase48
* Description            : Test the login functionality using valid credentials.
* Pre-requisites         : User "rahmaaaaaaaa" with password "rahmaaaa11" exists in the database.
* Test Expected output   : User should be able to login successfully and Session_User_id is updated.
* Bug                    : No
*************************************************************************************/

static void TestCase48(void)
{
	

	//valid credentials for login
	struct LoginCredentials_Type valid_credentials = {
		"rahmaaaaaaaa",  // Correct username
		"rahmaaaa11"      // Correct password
	};
	static unsigned int Session_User_id = -1;
	unsigned char login_result = Verify_User(valid_credentials.User_Name, valid_credentials.Password, &Session_User_id);

	printf("Login attempt with Username: %s, Password: %s\n", valid_credentials.User_Name, valid_credentials.Password);
	CU_ASSERT_EQUAL(login_result, Login_Successful); 
	CU_ASSERT_NOT_EQUAL(Session_User_id, (unsigned int)-1);  // Ensure session ID is updated

}
/************************************************************************************
* Test ID                : TestCase49
* Description            : Test the login functionality using invalid credentials.
* Pre-requisites         : User "rahmaaaaaaaa" with the correct password exists in the database.
* Test Expected output   : Login attempt should fail with "Password_incorrect" error.
* Bug                    : No
*************************************************************************************/

static void TestCase49(void)
{
	static unsigned int Session_User_id = -1;

	//login with invalid credentials (wrong password)
	struct LoginCredentials_Type invalid_credentials = {
		"rahmaaaaaaaa",  // Correct username
		"wrongpassword"   // Incorrect password
	};

	unsigned char invalid_login_result = Verify_User(invalid_credentials.User_Name, invalid_credentials.Password, &Session_User_id);
	CU_ASSERT_EQUAL(invalid_login_result, Password_incorrect); 
}

/************************************************************************************
* Test ID                : TestCase50
* Description            : Test the password change functionality in the customer module.
* Pre-requisites         : User is logged in with a valid Session_User_id.
*                          DB_LoginCredentials contains correct password for the logged-in user.
* Test Expected output   : Password successfully changed if inputs are valid.
* Bug                    : No
*************************************************************************************/
static void TestCase50(void)
{
	static unsigned int Session_User_id = 1;  

	
	strcpy(DB_LoginCredentials[Session_User_id].Password, "oldPassword");

	// Testing valid case : Correct current password, new password matches
	char Current_Password[] = "oldPassword";
	struct LoginCredentials_Form_Type ChangePasswordRequests = {
		.LoginCredentials.Password = "newPassword",
		.Password_Recheck = "newPassword"
	};

	// Simulate the flow of checking passwords
	if (strcmp(Current_Password, DB_LoginCredentials[Session_User_id].Password) == 0)
	{
		if (strcmp(ChangePasswordRequests.LoginCredentials.Password, ChangePasswordRequests.Password_Recheck) == 0)
		{
			strcpy(DB_LoginCredentials[Session_User_id].Password, ChangePasswordRequests.LoginCredentials.Password);
			printf("Password Changed Successfully \n");
			CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Session_User_id].Password, "newPassword");
		}
		else
		{
			printf("New Password mismatched \n");
			CU_FAIL("New passwords do not match");
		}
	}
	else
	{
		printf("Current Password is incorrect \n");
		CU_FAIL("Current password is incorrect");
	}
}

/************************************************************************************
* Test ID                : TestCase51
* Description            : Test the password change functionality with an incorrect current password.
* Pre-requisites         : User is logged in with a valid Session_User_id.
*                          DB_LoginCredentials contains the correct password for the logged-in user.
* Test Expected output   : Error message "Current Password is incorrect" is displayed, and password is not changed.
* Bug                    : No
*************************************************************************************/

static void TestCase51(void)
{
	static unsigned int Session_User_id = 1;  
    strcpy(DB_LoginCredentials[Session_User_id].Password, "old123");

	// incorrect current password, new password matches
	char Current_Password[] = "oldPassword";
	struct LoginCredentials_Form_Type ChangePasswordRequests = {
		.LoginCredentials.Password = "newPassword",
		.Password_Recheck = "newPassword"
	};

	// Simulate the flow of checking passwords
	if (strcmp(Current_Password, DB_LoginCredentials[Session_User_id].Password) == 0)
	{
		if (strcmp(ChangePasswordRequests.LoginCredentials.Password, ChangePasswordRequests.Password_Recheck) == 0)
		{
			strcpy(DB_LoginCredentials[Session_User_id].Password, ChangePasswordRequests.LoginCredentials.Password);
			printf("Password Changed Successfully \n");
			CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Session_User_id].Password, "newPassword");
		}
		else
		{
			printf("New Password mismatched \n");
			CU_FAIL("New passwords do not match");
		}
	}
	else
	{
		printf("Current Password is incorrect \n");
		CU_FAIL("Current password is incorrect");
	}
}

/************************************************************************************
* Test ID                : TestCase52
* Description            : Test the password change functionality where new password and confirmation password do not match.
* Pre-requisites         : User is logged in with a valid Session_User_id.
*                          DB_LoginCredentials contains the correct password for the logged-in user.
* Test Expected output   : Error message "New Password mismatched" is displayed, and password is not changed.
* Bug                    : No
*************************************************************************************/

static void TestCase52(void)
{
	static unsigned int Session_User_id = 1; 
	strcpy(DB_LoginCredentials[Session_User_id].Password, "oldPassword");

	// Correct current password, new password mismatches
	char Current_Password[] = "oldPassword";
	struct LoginCredentials_Form_Type ChangePasswordRequests = {
		.LoginCredentials.Password = "new12345678",
		.Password_Recheck = "newPassword"
	};

	// Simulate the flow of checking passwords
	if (strcmp(Current_Password, DB_LoginCredentials[Session_User_id].Password) == 0)
	{
		if (strcmp(ChangePasswordRequests.LoginCredentials.Password, ChangePasswordRequests.Password_Recheck) == 0)
		{
			strcpy(DB_LoginCredentials[Session_User_id].Password, ChangePasswordRequests.LoginCredentials.Password);
			printf("Password Changed Successfully \n");
			CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Session_User_id].Password, "newPassword");
		}
		else
		{
			printf("New Password mismatched \n");
			CU_FAIL("New passwords do not match");
		}
	}
	else
	{
		printf("Current Password is incorrect \n");
		CU_FAIL("Current password is incorrect");
	}
}

/************************************************************************************
* Test ID                : TestCase53
* Description            : Test the password change functionality where the new password is the same as the old password.
* Pre-requisites         : User is logged in with a valid Session_User_id.
*                          DB_LoginCredentials contains the correct password for the logged-in user.
* Test Expected output   : Message appears saying "you used old pass", and password won't change.
* Bug                    : Yes
*************************************************************************************/

static void TestCase53(void)
{
	static unsigned int Session_User_id = 1;
	strcpy(DB_LoginCredentials[Session_User_id].Password, "oldPassword");

	// current == new
	char Current_Password[] = "oldPassword";
	struct LoginCredentials_Form_Type ChangePasswordRequests = {
		.LoginCredentials.Password = "oldPassword",
		.Password_Recheck = "oldPassword"
	};

	// Simulate the flow of checking passwords
	if (strcmp(Current_Password, DB_LoginCredentials[Session_User_id].Password) == 0)
	{
		if (strcmp(ChangePasswordRequests.LoginCredentials.Password, ChangePasswordRequests.Password_Recheck) == 0)
		{
			strcpy(DB_LoginCredentials[Session_User_id].Password, ChangePasswordRequests.LoginCredentials.Password);
			printf("Password Changed Successfully \n");
			CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Session_User_id].Password, "oldPassword");
		}
		else
		{
			printf("New Password mismatched \n");
			CU_FAIL("New passwords do not match");
		}
	}
	else
	{
		printf("Current Password is incorrect \n");
		CU_FAIL("Current password is incorrect");
	}
}

/************************************************************************************
* Test ID                : TestCase54
* Description            : Test the functionality to print user data in the customer module.
* Pre-requisites         : User is logged in with a valid Session_User_id.
*                          DB_LoginCredentials contains valid user data for the logged-in user.
* Test Expected output   : User data should be printed correctly to the console.
* Bug                    : No
*************************************************************************************/
static void TestCase54(void)
{
	static unsigned int Session_User_id = 1;  

	
	strcpy(DB_LoginCredentials[Session_User_id].User_Name, "AdminUser1"); 
	strcpy(DB_LoginCredentials[Session_User_id].Password, "Edges123");  

	DBM_PrintUserData_User(Session_User_id);

}
/************************************************************************************
* Test ID                : TestCase55
* Description            : Test the successful enrollment in a valid course. (Course_id=1)
* Pre-requisites         : User is logged in with a valid Session_User_id.
*                          A valid Course_id within the range of available courses.
* Test Expected output   : User should be added to the course and a success message should be printed.
* Bug                    : No
*************************************************************************************/
static void TestCase55(void)
{
	static unsigned int Session_User_id = 1; 
	int Course_id = 1;

	
	int RET = AddStudentToCourse(Course_id, Session_User_id);
	CU_ASSERT_EQUAL(RET, Enrolled);

	printf("You Are Added To This Course Reservation \n"); 
	
}

/************************************************************************************
* Test ID                : TestCase56
* Description            : Test the scenario where the selected course number is invalid.
* Pre-requisites         : User is logged in with a valid Session_User_id.
*                          Course_id is set to an invalid value (out of range).
* Test Expected output   : Error message indicating the course is out of range should be printed.
* Bug                    : No
*************************************************************************************/
static void TestCase56(void)
{
	static unsigned int Session_User_id = 1; 
	int Course_id = MAX_COURSES + 1; 

	// Directly call the function to add the student to the course
	int RET = AddStudentToCourse(Course_id, Session_User_id);

	
	CU_ASSERT_NOT_EQUAL(RET, Enrolled); 

	printf("Out of range Course Try again \n"); 
}

/************************************************************************************
* Test ID                : TestCase57
* Description            : Test the scenario where the user is already enrolled in the selected course.
* Pre-requisites         : User is logged in with a valid Session_User_id.
* Test Expected output   : A message indicating the user is already enrolled should be printed.
* Bug                    : No
*************************************************************************************/

static void TestCase57(void) {
	static unsigned int Session_User_id = 1; 
	int Course_id = 1;

	// enroll the user in the course
	int RET = AddStudentToCourse(Course_id, Session_User_id);

	printf("First enrollment attempt: RET = %d\n", RET);

	// Now try to enroll the same user in the same course again
	RET = AddStudentToCourse(Course_id, Session_User_id);

	printf("Second enrollment attempt: RET = %d\n", RET);

	CU_ASSERT_EQUAL(RET, AlreadyEnrolled);

	printf("You Are Already Enrolled to this Course \n");
}

static void TestCase58(void) {
	
	int Course_id = 1; 

	// enroll the user in the course
	int RET = AddStudentToCourse(Course_id, 1);
	int RET2 = AddStudentToCourse(Course_id, 2);
	int RET3 = AddStudentToCourse(Course_id, 3);
	int RET4 = AddStudentToCourse(Course_id, 4);
	int RET5 = AddStudentToCourse(Course_id, 5);
	int RET6 = AddStudentToCourse(Course_id, 6);

	// Check for expected return value indicating Full capacity
	CU_ASSERT_EQUAL(RET6, CapacityCompleted);
	printf(" enrollment attempt: RET6 = %d\n", RET6);

	printf("You can;t be added beacuse of full capacity \n"); // Expected output
}

/************************************************************************************
* Test ID                : TestCase59
* Description            : Test the successful enrollment in a valid course. (Course_id=2)
* Pre-requisites         : User is logged in with a valid Session_User_id.
*                          A valid Course_id within the range of available courses.
* Test Expected output   : User should be added to the course and a success message should be printed.
* Bug                    : No
*************************************************************************************/

static void TestCase59(void)
{
	static unsigned int Session_User_id = 1; 
	int Course_id = 2; 

	// Directly call the function to add the student to the course
	int RET = AddStudentToCourse(Course_id, Session_User_id);

	// Check for expected return value indicating enrollment success
	CU_ASSERT_EQUAL(RET, Enrolled);

	printf("You Are Added To This Course Reservation \n");

}

/************************************************************************************
* Test ID                : TestCase60
* Description            : Test the successful enrollment in a valid course. (Course_id=3)
* Pre-requisites         : User is logged in with a valid Session_User_id.
*                          A valid Course_id within the range of available courses.
* Test Expected output   : User should be added to the course and a success message should be printed.
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase61
* Description            : Test the successful enrollment in a valid course. (Course_id=5)
* Pre-requisites         : User is logged in with a valid Session_User_id.
*                          A valid Course_id within the range of available courses.
* Test Expected output   : User should be added to the course and a success message should be printed.
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase62
* Description            : Test the successful enrollment in a valid course. (Course_id=6)
* Pre-requisites         : User is logged in with a valid Session_User_id.
*                          A valid Course_id within the range of available courses.
* Test Expected output   : User should be added to the course and a success message should be printed.
* Bug                    : No
*************************************************************************************/

/************************************************************************************
* Test ID                : TestCase63
* Description            : Test the correctness of displaying student courses and
*                          adding a new course for a student.
* Pre-requisites         : User is logged in with a valid Session_User_id.
*                          User must not be already enrolled in the specified Course_id.
* Test Expected output   : The student's courses should be displayed correctly,
*                          and a confirmation of successful enrollment should be printed.
* Bug                    : No
*************************************************************************************/


static void TestCase63(void)
{
	static unsigned int Session_User_id = 2; 
	int Course_id = 2;

	ShowStudentCourses(Session_User_id);


	int RET = AddStudentToCourse(Course_id, Session_User_id);
	CU_ASSERT_EQUAL(RET, Enrolled);


	ShowStudentCourses(Session_User_id);
}

void Main_Test_Runner(void)
{
	/* initialize the Registry */
	CU_initialize_registry();

	/* Adding Test Suite to the Registry */
	CU_pSuite suite_positive = CU_add_suite("Creaet Valid Account", test1_start, test1_end);
	CU_pSuite suite_negative = CU_add_suite("Creaet InValid Account", test2_start, test2_end);
	CU_pSuite suite = CU_add_suite("Input check", test3_start, test3_end);
	CU_pSuite suite2 = CU_add_suite("delete acc", test43_start, test43_end);
	CU_pSuite course_registration = CU_add_suite("Course Registration", NULL, NULL);
	CU_pSuite Printing = CU_add_suite("Printing specific users", test46_start, test46_end);
	CU_pSuite Printing_all = CU_add_suite("Printing all users", test47_start, NULL);
	CU_pSuite suite_customer = CU_add_suite("Test Suite for Customer Functionality", TestCase48_start, TestCase48_end);
	CU_pSuite after_login = CU_add_suite("Testing change current passowrd functionality ", NULL, NULL);
	CU_pSuite print_info = CU_add_suite("Printing customer info ", NULL, NULL);
	CU_pSuite course_Enrollment = CU_add_suite("testing AddStudentToCourse functionality ", NULL, NULL);
	CU_pSuite course_Enrollment2 = CU_add_suite("testing AddStudentToCourse in already enrolled/full capacity ", NULL, NULL);
	CU_pSuite Printing_enrolled_courses = CU_add_suite("Printing_enrolled_courses", NULL, NULL);


	/* Adding Test Cases to the Test Suite*/
	CU_add_test(suite_positive, "Creaet Valid Account", TestCase1);
	//this suite is expected to fail and not to run due to to the invalid creation of the account 
	CU_add_test(suite_negative, "Creaet InValid Account", TestCase2);
	CU_add_test(suite, "try multiple inputs", TestCase3);
	CU_add_test(suite2, "testing delete acc", TestCase43);
	CU_add_test(course_registration, "enroll student To course", TestCase44);
	CU_add_test(course_registration, "enroll student in full capacity course", TestCase45);
	CU_add_test(Printing, "printing specific users", TestCase46);
	CU_add_test(Printing_all, "printing all users", TestCase47);
	CU_add_test(suite_customer, "Create Account and Verify Login Test with valid credentials", TestCase48);
	CU_add_test(suite_customer, "Create Account and Verify Login Test with Invalid credentials", TestCase49);
	CU_add_test(after_login, "valid scenario", TestCase50);
	CU_add_test(after_login, "Invalid scenario : invalid current password", TestCase51);
	CU_add_test(after_login, "Invalid scenario : mismatch new passwords", TestCase52);
	CU_add_test(after_login, "Invalid scenario : New pass == old pass", TestCase53);
	CU_add_test(print_info, "printing", TestCase54);
	CU_add_test(course_Enrollment, "testing enrolled case", TestCase55);
	CU_add_test(course_Enrollment, "testing enrollment with unvalid course number", TestCase56);
	CU_add_test(course_Enrollment2, "testing the already enrolled scenario", TestCase57);
	CU_add_test(course_Enrollment2, "testing the capacity full scenario", TestCase58);
	CU_add_test(course_Enrollment, "testing enrollment with course numbers", TestCase59);
	CU_add_test(Printing_enrolled_courses, "testing printing of courses", TestCase63);




	/* Running the Test Suite through Basic Console */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	/* Running the Test Suite through Console interactive */
	 CU_console_run_tests();

	/* Clear the registry after test finished */
	CU_cleanup_registry();
}
