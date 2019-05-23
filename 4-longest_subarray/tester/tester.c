/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:03:05 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/22 13:03:06 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>//	printf()

char	*longest_subarray(char *arr);

/*
**	Given no args, it runs tests from the subject + moulinette tests.
**	Given args, it runs those.
*/

#define SUBJ_TEST_COUNT 4
static char*	g_subj_tests[] = {
	"134", "454", "1357913579024680213579", "2010102"
};
static char*	g_subj_answers[] = {
	"34", "45", "79135790246802", "0101"
};

#define MOUL_TEST_COUNT 9
static char*	g_moul_tests[] = {
	"0",
	"10",
	"110",
	"1110110111",
	"42424221422124332536547",
	"222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222202222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222202222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222223222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222122222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222220222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222253222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222322222222222222222222222222222222222222222222222222222022222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222292222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222022222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222",
	"2222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222022222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222022222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222212222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222022222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222225222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222322222222222222222222222222222222222222222222222222222022222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222292222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222022222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222",
	"4865312337864531297864531228978645312879645318879645312874531201268789787964531278964531255641522916874587917858871787151758456242481414681728786541813727148728154418354144157175151715714144477414141434534343885584541781681688468695584899484828246824685814646836845656446646464546565446586468384142356453687685368345687383738464189468628346884683484814646846846846447678568145814248141468172878654181372714872815441835414415717515171571414447741414143453434388558454178168168846869558489948482824682468581464683684565644664646454656544658646838414235645368768536834568738373846418946862834688468348481464684684684644761728786541813727148728154418354144157175151715714144477414141434534343885584541781681688468695584899484828246824685814646836845656446646464546565446586468384142356453687685368345687383738464189468628346884683484814646846846846447678568147287865418137271487281544183541441571751517157141444774141414345343438855845417816816884686955848994848282468246858146468368456564466464645465654465864683841423564536876853683456873837384641894686283468846834848146468468468464476785681458142481414681728786541813727148728154418354144157175151715714144477414141434534343885584541781681688468695584899484828246824685814646836845656446646464546565446586468384142356453687685368345687383738464189468628346884683484814646846846846447617287865418137271487281544183541441571751517157141444774141414345343438855845417816816884686955848994848282468248145814248141468172878654181372714872815441835414415717515171571414447741414143453434388558454178168168846869558489948482824682468581464683684565644664646454656544658646838414235645368768536834568738373846418946862834688468348481464684684684644761728786541813727148728154418354144157175151715714144477414141434534343885584541781681688468695584899484828246824685814646836845656446646464546565446586468384142356453687685368345687383738464189468628346884683484814646846846846447678568147287865418137271487281544183541441571751517157141444774141414345343438855845417816816884686955848994848282468246858146468368456564466464645465654465864683841423564536876853683456873837384641894686283468846834848146468468468464476785",
	"1357913579024680213579"
};
static char*	g_moul_answers[] = {
	"",
	"10",
	"10",
	"0110",
	"1422124332536547",
	"2253",
	"21",
	"531233786453129786453122897864531287964531887964531287453120126878978796453127896453125564152291687458791785887178715175845624248141468172878654181372714872815441835414415717515171571414447741414143453434388558454178168168846869558489948482824682468581464683",
	"79135790246802"
};

void	run_tests(int count, char *tests[], char* answers[])
{
	for (int i = 0; i < count; ++i)
	{
		printf("Test %d:\n", i + 1);
		printf("longest_subarray(\"%s\");\n", tests[i]);
		printf("should return = \"%s\"\n", answers[i]);
		printf("  your return = \"%s\"\n", longest_subarray(tests[i]));
		if (i + 1 < count)
			printf("\n");
	}
}

int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("TESTS FROM SUBJECT:\n");
		run_tests(SUBJ_TEST_COUNT, g_subj_tests, g_subj_answers);
		printf("\nTESTS FROM TRACE:\n");
		run_tests(MOUL_TEST_COUNT, g_moul_tests, g_moul_answers);
	}
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			printf("Test %d:\n", i);
			printf("longest_subarray(\"%s\");\n", argv[i]);
			printf("your return = \"%s\"\n", longest_subarray(argv[i]));
			if (i + 1 < argc)
				printf("\n");
		}
	}
}