#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = fopen("orig.txt", "r");
    FILE *output = fopen("output.txt", "w");
    if (!fp) {
        printf("ERROR opening input file orig.txt\n");
        exit(0);
    }
    int i = 0;
    char append[50], find[50];
    double orig_sum_a = 0.0, orig_sum_f = 0.0, orig_a, orig_f;
    for (i = 0; i < 100; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %lf %lf\n", append, find,&orig_a, &orig_f);
        orig_sum_a += orig_a;
        orig_sum_f += orig_f;
    }
    fclose(fp);

    fp = fopen("opt.txt", "r");
    if (!fp) {
            printf("ERROR opening input file opt.txt\n");
            exit(0);
    }
	
    double opt_sum_a = 0.0, opt_sum_f = 0.0, opt_a, opt_f;
    for (i = 0; i < 100; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %lf %lf\n", append, find,&opt_a, &opt_f);
        opt_sum_a += opt_a;
        opt_sum_f += opt_f;
    }
    fclose(fp);

	/* open hash.txt */
	fp = fopen("hash.txt", "r");
	if (!fp) {
		printf("ERROR opening input file hash.txt\n");
		exit(0);
	}

	double hash_sum_a = 0.0, hash_sum_f = 0.0, hash_a, hash_f;
	for (i = 0; i < 100; i++) {
		if (feof(fp)) {
			printf("ERROR: You need 100 datum instead of %d\n", i);
			printf("run 'make run' longer to get enough information\n\n");
			exit(0);
		}
		fscanf(fp, "%s %s %lf %lf\n", append, find, &hash_a, &hash_f);
		hash_sum_a += hash_a;
		hash_sum_f += hash_f;
	}

	fclose(fp);

	/* open mp.txt */
	fp = fopen("mp.txt", "r");
	if (!fp) {
		printf("ERROR opening input file mp.txt\n");
		exit(0);
	}

	double mp_sum_a = 0.0, mp_sum_f = 0.0, mp_a, mp_f;
	for (i = 0; i < 100; i++) {
		if (feof(fp)) {
			printf("ERROR: You need 100 datum instead of %d\n", i);
			printf("run 'make run' longer to get enough information\n\n");
			exit(0);
		}
		fscanf(fp, "%s %s %lf %lf\n", append, find, &mp_a, &mp_f);
		mp_sum_a += mp_a;
		mp_sum_f += mp_f;
	}

	fclose(fp);
    fprintf(output, "append() %lf %lf %lf %lf\n",orig_sum_a / 100.0, opt_sum_a / 100.0, hash_sum_a / 100.0, mp_sum_a / 100.0);
    fprintf(output, "findName() %lf %lf %lf %lf\n", orig_sum_f / 100.0, opt_sum_f / 100.0, hash_sum_f / 100.0, mp_sum_f / 100.0);
    fclose(output);
    return 0;
}
