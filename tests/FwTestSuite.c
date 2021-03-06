/**
 * @file
 * @ingroup tsGroup
 * Test Suite for FW State Machine Module and FW Procedure Module.
 * This file defines the <code>main</code> program for the test suite.
 * The test suite executes a number of <i>test cases</i> in sequence and reports
 * the outcome of each test case.
 * Test cases for the state machine module are defined in <code>FwSmTestCases.h</code>.
 * Test cases for the procedure module are defined in <code>FwPrTestCases.h</code>.
 *
 * @author Vaclav Cechticky <vaclav.cechticky@pnp-software.com>
 * @author Alessandro Pasetti <pasetti@pnp-software.com>
 * @copyright P&P Software GmbH, 2013, All Rights Reserved
 *
 * This file is part of the FW Profile.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * For information on alternative licensing, please contact P&P Software GmbH.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FwSmConstants.h"
#include "FwPrConstants.h"
#include "FwRtConstants.h"
#include "FwSmTestCases.h"
#include "FwPrTestCases.h"
#include "FwRtTestCases.h"

/** The number of state machine tests in the test suite. */
#define N_OF_SM_TESTS 67
/** The number of procedure tests in the test suite. */
#define N_OF_PR_TESTS 37
/** The number of RT Container tests in the test suite. */
#define N_OF_RT_TESTS 13

/**
 * Main program for the test suite.
 * The test suite executes a number of <i>test cases</i> in sequence and reports
 * the outcome of each test case.
 * Test cases for the state machine module are defined in <code>FwSmTestCases.h</code>.
 * Test cases for the procedure module are defined in <code>FwPrTestCases.h</code>.
 * @return always returns EXIT_SUCCESS
 */
int main() {
	int i;
	FwSmTestOutcome_t smOutcome;
	FwPrTestOutcome_t prOutcome;
	FwRtTestOutcome_t rtOutcome;
	char* smTestNames[N_OF_SM_TESTS];
	char* prTestNames[N_OF_PR_TESTS];
	char* rtTestNames[N_OF_RT_TESTS];
	typedef FwSmTestOutcome_t (*SmTestCase_t)();
	typedef FwPrTestOutcome_t (*PrTestCase_t)();
	typedef FwRtTestOutcome_t (*RtTestCase_t)();
	SmTestCase_t smTestCases[N_OF_SM_TESTS]; /* array of pointers to SM test case functions */
	PrTestCase_t prTestCases[N_OF_PR_TESTS]; /* array of pointers to PR test case functions */
	RtTestCase_t rtTestCases[N_OF_RT_TESTS]; /* array of pointers to RT test case functions */
	int skipRtTest = 0;

	/* Set the names of the SM tests and the functions executing the tests */
	smTestNames[0] = (char*)"FwSm_Start1";
	smTestCases[0] = &FwSmTestCaseStart1;
	smTestNames[1] = (char*)"FwSm_Start2";
	smTestCases[1] = &FwSmTestCaseStart2;
	smTestNames[2] = (char*)"FwSm_Start3";
	smTestCases[2] = &FwSmTestCaseStart3;
	smTestNames[3] = (char*)"FwSm_Stop1";
	smTestCases[3] = &FwSmTestCaseStop1;
	smTestNames[4] = (char*)"FwSm_Stop2";
	smTestCases[4] = &FwSmTestCaseStop2;
	smTestNames[5] = (char*)"FwSm_Stop3";
	smTestCases[5] = &FwSmTestCaseStop3;
	smTestNames[6] = (char*)"FwSm_Execute1";
	smTestCases[6] = &FwSmTestCaseExecute1;
	smTestNames[7] = (char*)"FwSm_Execute2";
	smTestCases[7] = &FwSmTestCaseExecute2;
	smTestNames[8] = (char*)"FwSm_Execute3";
	smTestCases[8] = &FwSmTestCaseExecute3;
	smTestNames[9] = (char*)"FwSm_SelfTrans1";
	smTestCases[9] = &FwSmTestCaseSelfTrans1;
	smTestNames[10] = (char*)"FwSm_Trans1";
	smTestCases[10] = &FwSmTestCaseTrans1;
	smTestNames[11] = (char*)"FwSm_Trans2";
	smTestCases[11] = &FwSmTestCaseTrans2;
	smTestNames[12] = (char*)"FwSm_Trans3";
	smTestCases[12] = &FwSmTestCaseTrans3;
	smTestNames[13] = (char*)"FwSm_Execute4";
	smTestCases[13] = &FwSmTestCaseExecute4;
	smTestNames[14] = (char*)"FwSm_Trans4";
	smTestCases[14] = &FwSmTestCaseTrans4;
	smTestNames[15] = (char*)"FwSm_DescStatic1";
	smTestCases[15] = &FwSmTestCaseDescDir1;
	smTestNames[16] = (char*)"FwSm_ConfigErr1";
	smTestCases[16] = &FwSmTestCaseConfigErr1;
	smTestNames[17] = (char*)"FwSm_ConfigCheck1";
	smTestCases[17] = &FwSmTestCaseCheck1;
	smTestNames[18] = (char*)"FwSm_ConfigCheck2";
	smTestCases[18] = &FwSmTestCaseCheck2;
	smTestNames[19] = (char*)"FwSm_ConfigCheck3";
	smTestCases[19] = &FwSmTestCaseCheck3;
	smTestNames[20] = (char*)"FwSm_ConfigCheck4";
	smTestCases[20] = &FwSmTestCaseCheck4;
	smTestNames[21] = (char*)"FwSm_ConfigCheck5";
	smTestCases[21] = &FwSmTestCaseCheck5;
	smTestNames[22] = (char*)"FwSm_ConfigCheck6";
	smTestCases[22] = &FwSmTestCaseCheck6;
	smTestNames[23] = (char*)"FwSm_ConfigCheck7";
	smTestCases[23] = &FwSmTestCaseCheck7;
	smTestNames[24] = (char*)"FwSm_ConfigCheck8";
	smTestCases[24] = &FwSmTestCaseCheck8;
	smTestNames[25] = (char*)"FwSm_ConfigCheck9";
	smTestCases[25] = &FwSmTestCaseCheck9;
	smTestNames[26] = (char*)"FwSm_ConfigCheck10";
	smTestCases[26] = &FwSmTestCaseCheck10;
	smTestNames[27] = (char*)"FwSm_Trans5";
	smTestCases[27] = &FwSmTestCaseTrans5;
	smTestNames[28] = (char*)"FwSm_DummySM1";
	smTestCases[28] = &FwSmTestCaseDummySM1;
	smTestNames[29] = (char*)"FwSm_DummySM9";
	smTestCases[29] = &FwSmTestCaseDummySM9;
	smTestNames[30] = (char*)"FwSm_ConfigCheck11";
	smTestCases[30] = &FwSmTestCaseCheck11;
	smTestNames[31] = (char*)"FwSm_ConfigCheck12";
	smTestCases[31] = &FwSmTestCaseCheck12;
	smTestNames[32] = (char*)"FwSm_Trans6";
	smTestCases[32] = &FwSmTestCaseTrans6;
	smTestNames[33] = (char*)"FwSm_ConfigCheck14";
	smTestCases[33] = &FwSmTestCaseCheck14;
	smTestNames[34] = (char*)"FwSm_ConfigCheck15";
	smTestCases[34] = &FwSmTestCaseCheck15;
	smTestNames[35] = (char*)"FwSm_ConfigTransErr1";
	smTestCases[35] = &FwSmTestCaseTransErr1;
	smTestNames[36] = (char*)"FwSm_DummySM3";
	smTestCases[36] = &FwSmTestCaseDummySM3;
	smTestNames[37] = (char*)"FwSm_TransErr2";
	smTestCases[37] = &FwSmTestCaseTransErr2;
	smTestNames[38] = (char*)"FwSm_ConfigCheck16";
	smTestCases[38] = &FwSmTestCaseCheck16;
	smTestNames[39] = (char*)"FwSm_DescStatic2";
	smTestCases[39] = &FwSmTestCaseDescStatic2;
	smTestNames[40] = (char*)"FwSm_DummySM9Static";
	smTestCases[40] = &FwSmTestCaseDummySM9Static;
	smTestNames[41] = (char*)"FwSm_ConfigCheck17";
	smTestCases[41] = &FwSmTestCaseCheck17;
	smTestNames[42] = (char*)"FwSm_ConfigCheck18";
	smTestCases[42] = &FwSmTestCaseCheck18;
	smTestNames[43] = (char*)"FwSm_ConfigCheck19";
	smTestCases[43] = &FwSmTestCaseCheck19;
	smTestNames[44] = (char*)"FwSm_ConfigCheck20";
	smTestCases[44] = &FwSmTestCaseCheck20;
	smTestNames[45] = (char*)"FwSm_DescStatic3";
	smTestCases[45] = &FwSmTestCaseDescStatic3;
	smTestNames[46] = (char*)"FwSm_Print1";
	smTestCases[46] = &FwSmTestCasePrint1;
	smTestNames[47] = (char*)"FwSm_Print2";
	smTestCases[47] = &FwSmTestCasePrint2;
	smTestNames[48] = (char*)"FwSm_Execute5";
	smTestCases[48] = &FwSmTestCaseExecute5;
	smTestNames[49] = (char*)"FwSm_Derived1";
	smTestCases[49] = &FwSmTestCaseDer1;
	smTestNames[50] = (char*)"FwSm_Derived2";
	smTestCases[50] = &FwSmTestCaseDer2;
	smTestNames[51] = (char*)"FwSm_DerivedConfigErr1";
	smTestCases[51] = &FwSmTestCaseDerConfigErr1;
	smTestNames[52] = (char*)"FwSm_DerivedEmbed1";
	smTestCases[52] = &FwSmTestCaseDerEmbed1;
	smTestNames[53] = (char*)"FwSm_Junction1";
	smTestCases[53] = &FwSmTestCaseJunction1;
	smTestNames[54] = (char*)"FwSm_Derived3";
	smTestCases[54] = &FwSmTestCaseDer3;
	smTestNames[55] = (char*)"FwSm_Derived4";
	smTestCases[55] = &FwSmTestCaseDer4;
	smTestNames[56] = (char*)"FwSm_DerivedErr1";
	smTestCases[56] = &FwSmTestCaseDerErr1;
	smTestNames[57] = (char*)"FwSm_Derived5";
	smTestCases[57] = &FwSmTestCaseDer5;
	smTestNames[58] = (char*)"FwSm_ConfigErr2";
	smTestCases[58] = &FwSmTestCaseConfigErr2;
	smTestNames[59] = (char*)"FwSm_DerConfig1";
	smTestCases[59] = &FwSmTestCaseDerConfig1;
	smTestNames[60] = (char*)"FwSm_DerConfig2";
	smTestCases[60] = &FwSmTestCaseDerConfig2;
	smTestNames[61] = (char*)"FwSm_ExecCnt1";
	smTestCases[61] = &FwSmTestCaseExecCnt1;
	smTestNames[62] = (char*)"FwSm_Derived6";
	smTestCases[62] = &FwSmTestCaseDer6;
	smTestNames[63] = (char*)"FwSm_Trans7";
	smTestCases[63] = &FwSmTestCaseTrans7;
	smTestNames[64] = (char*)"FwSm_Trans8";
	smTestCases[64] = &FwSmTestCaseTrans8;
	smTestNames[65] = (char*)"FwSm_Check21";
	smTestCases[65] = &FwSmTestCaseCheck21;
	smTestNames[66] = (char*)"FwSm_Check22";
	smTestCases[66] = &FwSmTestCaseCheck22;

	/* Set the names of the PR tests and the functions executing the tests */
	prTestNames[0] = (char*)"FwPr_Start1";
	prTestCases[0] = &FwPrTestCaseStart1;
	prTestNames[1] = (char*)"FwPr_Stop1";
	prTestCases[1] = &FwPrTestCaseStop1;
	prTestNames[2] = (char*)"FwPr_Execute1";
	prTestCases[2] = &FwPrTestCaseExecute1;
	prTestNames[3] = (char*)"FwPr_Execute2";
	prTestCases[3] = &FwPrTestCaseExecute2;
	prTestNames[4] = (char*)"FwPr_Execute3";
	prTestCases[4] = &FwPrTestCaseExecute3;
	prTestNames[5] = (char*)"FwPr_Execute4";
	prTestCases[5] = &FwPrTestCaseExecute4;
	prTestNames[6] = (char*)"FwPr_Execute5";
	prTestCases[6] = &FwPrTestCaseExecute5;
	prTestNames[7] = (char*)"FwPr_Check1";
	prTestCases[7] = &FwPrTestCaseCheck1;
	prTestNames[8] = (char*)"FwPr_Execute5Static";
	prTestCases[8] = &FwPrTestCaseExecute5Static;
	prTestNames[9] = (char*)"FwPr_Execute4Static";
	prTestCases[9] = &FwPrTestCaseExecute4Static;
	prTestNames[10] = (char*)"FwPr_Check2";
	prTestCases[10] = &FwPrTestCaseCheck2;
	prTestNames[11] = (char*)"FwPr_Execute6";
	prTestCases[11] = &FwPrTestCaseExecute6;
	prTestNames[12] = (char*)"FwPr_Check3";
	prTestCases[12] = &FwPrTestCaseCheck3;
	prTestNames[13] = (char*)"FwPr_Execute7";
	prTestCases[13] = &FwPrTestCaseExecute7;
	prTestNames[14] = (char*)"FwPr_Check4";
	prTestCases[14] = &FwPrTestCaseCheck4;
	prTestNames[15] = (char*)"FwPr_Check5";
	prTestCases[15] = &FwPrTestCaseCheck5;
	prTestNames[16] = (char*)"FwPr_Check6";
	prTestCases[16] = &FwPrTestCaseCheck6;
	prTestNames[17] = (char*)"FwPr_Check7";
	prTestCases[17] = &FwPrTestCaseCheck7;
	prTestNames[18] = (char*)"FwPr_Check8";
	prTestCases[18] = &FwPrTestCaseCheck8;
	prTestNames[19] = (char*)"FwPr_Check9";
	prTestCases[19] = &FwPrTestCaseCheck9;
	prTestNames[20] = (char*)"FwPr_Check10";
	prTestCases[20] = &FwPrTestCaseCheck10;
	prTestNames[21] = (char*)"FwPr_Check11";
	prTestCases[21] = &FwPrTestCaseCheck11;
	prTestNames[22] = (char*)"FwPr_Check12";
	prTestCases[22] = &FwPrTestCaseCheck12;
	prTestNames[23] = (char*)"FwPr_Run1";
	prTestCases[23] = &FwPrTestCaseRun1;
	prTestNames[24] = (char*)"FwPr_Der1";
	prTestCases[24] = &FwPrTestCaseDer1;
	prTestNames[25] = (char*)"FwPr_DerCheck1";
	prTestCases[25] = &FwPrTestCaseDerCheck1;
	prTestNames[26] = (char*)"FwPr_DerCheck2";
	prTestCases[26] = &FwPrTestCaseDerCheck2;
	prTestNames[27] = (char*)"FwPr_Der2";
	prTestCases[27] = &FwPrTestCaseDer2;
	prTestNames[28] = (char*)"FwPr_DerCheck3";
	prTestCases[28] = &FwPrTestCaseDerCheck3;
	prTestNames[29] = (char*)"FwPr_Execute4Dir";
	prTestCases[29] = &FwPrTestCaseExecute4Dir;
	prTestNames[30] = (char*)"FwPr_DerCheck4";
	prTestCases[30] = &FwPrTestCaseDerCheck4;
	prTestNames[31] = (char*)"FwPr_Execute8";
	prTestCases[31] = &FwPrTestCaseExecute8;
	prTestNames[32] = (char*)"FwPr_DerCheck5";
	prTestCases[32] = &FwPrTestCaseDerCheck5;
	prTestNames[33] = (char*)"FwPr_Der3";
	prTestCases[33] = &FwPrTestCaseDer3;
	prTestNames[34] = (char*)"FwPr_Exec9";
	prTestCases[34] = &FwPrTestCaseExecute9;
	prTestNames[35] = (char*)"FwPr_Check13";
	prTestCases[35] = &FwPrTestCaseCheck13;
	prTestNames[36] = (char*)"FwPr_Check14";
	prTestCases[36] = &FwPrTestCaseCheck14;

	/* Set the names of the RT tests and the functions executing the tests */
	rtTestNames[0] = (char*)"FwRt_SetAttr1";
	rtTestCases[0] = &FwRtTestCaseSetAttr1;
	rtTestNames[1] = (char*)"FwRt_RunDefault1";
	rtTestCases[1] = &FwRtTestCaseRunDefault1;
	rtTestNames[2] = (char*)"FwRt_Run1";
	rtTestCases[2] = &FwRtTestCaseRun1;
	rtTestNames[3] = (char*)"FwRt_Run2";
	rtTestCases[3] = &FwRtTestCaseRun2;
	rtTestNames[4] = (char*)"FwRt_Run3";
	rtTestCases[4] = &FwRtTestCaseRun3;
	rtTestNames[5] = (char*)"FwRt_StressRun1";
	rtTestCases[5] = &FwRtTestCaseStressRun1;
	rtTestNames[6] = (char*)"FwRt_StressRun2";
	rtTestCases[6] = &FwRtTestCaseStressRun2;
	rtTestNames[7] = (char*)"FwRt_StressRun3";
	rtTestCases[7] = &FwRtTestCaseStressRun3;
	rtTestNames[8] = (char*)"FwRt_RunNonNullAttr1";
	rtTestCases[8] = &FwRtTestCaseRunNonNullAttr1;
	rtTestNames[9] = (char*)"FwRt_StressRun4";
	rtTestCases[9] = &FwRtTestCaseStressRun4;
	rtTestNames[10] = (char*)"FwRt_StressRun5";
	rtTestCases[10] = &FwRtTestCaseStressRun5;
	rtTestNames[11] = (char*)"FwRt_StressRun6";
	rtTestCases[11] = &FwRtTestCaseStressRun6;
	rtTestNames[12] = (char*)"FwRt_TestCaseSetAction1";
	rtTestCases[12] = &FwRtTestCaseSetAction1;

	/* Run state machine test cases in sequence */
	for (i=0; i<N_OF_SM_TESTS; i++) {
		smOutcome = smTestCases[i]();
		if (smOutcome == smTestCaseSuccess)
			printf("Test case %s ran successfully ...\n", smTestNames[i]);
		else
			printf("Test case %s failed with failure code %i\n", smTestNames[i], smOutcome);
	}

	/* Run procedure test cases in sequence */
	for (i=0; i<N_OF_PR_TESTS; i++) {
		prOutcome = prTestCases[i]();
		if (prOutcome == prTestCaseSuccess)
			printf("Test case %s ran successfully ...\n", prTestNames[i]);
		else
			printf("Test case %s failed with failure code %i\n", prTestNames[i], prOutcome);
	}

	printf("\nThe next set of test cases cover the RT Container.\n");
	printf("These test cases require an implementation of the POSIX library\n");
	printf("and may fail depending on this implementation or on the \n");
	printf("characteristics of the OS of the host platform.\n");
	printf("Some of these tests take several seconds to complete.\n");
	printf("The tests may be skipped by setting flag skipRtTest to 1 in the\n");
	printf("main program of the Test Suite application.\n\n");

	/* Check whether the RT Container tests should be skipped */
	if (skipRtTest == 1)
		return EXIT_SUCCESS;

	/* Run RT Container test cases in sequence */
	for (i=0; i<N_OF_RT_TESTS; i++) {
		rtOutcome = rtTestCases[i]();
		if (rtOutcome == rtTestCaseSuccess)
			printf("Test case %s ran successfully ...\n", rtTestNames[i]);
		else
			printf("Test case %s failed with failure code %i\n", rtTestNames[i], rtOutcome);
	}

	/* Useful code to print out the size of types used by the C1 Implementation */
	/* printf("Size of pthread_t: %i\n",sizeof(pthread_t)); */
	/* printf("Size of pthread_mutex_t: %i\n",sizeof(pthread_mutex_t)); */
	/* printf("Size of pthread_cond_t: %i\n",sizeof(pthread_cond_t)); */
	/* printf("Size of FwRtAction_t: %i\n",sizeof(FwRtAction_t)); */
	/* printf("Size of struct FwRtDesc: %i\n",sizeof(struct FwRtDesc)); */

	return EXIT_SUCCESS;
}

