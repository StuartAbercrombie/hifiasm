#ifndef __COMMAND_LINE_PARSER__
#define __COMMAND_LINE_PARSER__

#include <pthread.h>

#define HA_VERSION "0.3.0-dirty-r220"

#define VERBOSE 0

#define HA_F_NO_HPC       0x1
#define HA_F_NO_KMER_FLT  0x2
#define HA_F_VERBOSE_GFA  0x4
#define HA_F_WRITE_EC     0x8
#define HA_F_WRITE_PAF    0x10
#define HA_F_SKIP_TRIOBIN 0x20

typedef struct {
	int flag;
    int num_reads;
    char** read_file_names;
    char* output_file_name;
    char* required_read_name;
	char *fn_bin_yak[2];
	char *fn_bin_list[2];
    int thread_num;
    int k_mer_length;
	int mz_win;
	int bf_shift;
	float high_factor; // coverage cutoff set to high_factor*hom_cov
	int max_n_chain; // fall-back max number of chains to consider
    int k_mer_min_freq;
    int k_mer_max_freq;
    int load_index_from_disk;
    int write_index_to_disk;
    int number_of_round;
    int adapterLen;
    int clean_round;
    int roundID;
    int max_hang_Len;
    int gap_fuzz;
    int min_overlap_Len;
    int min_overlap_coverage;
    int max_short_tip;
    int min_cnt;
    int mid_cnt;

    float max_hang_rate;
    float min_drop_rate;
    float max_drop_rate;

    long long small_pop_bubble_size;
    long long large_pop_bubble_size;
    long long num_bases;
    long long num_corrected_bases;
    long long num_recorrected_bases;
	long long mem_buf;
    long long coverage;
} hifiasm_opt_t;

extern hifiasm_opt_t asm_opt;

void init_opt(hifiasm_opt_t* asm_opt);
void destory_opt(hifiasm_opt_t* asm_opt);
void ha_opt_reset_to_round(hifiasm_opt_t* asm_opt, int round);
void ha_opt_update_cov(hifiasm_opt_t *opt, int hom_cov);
int CommandLine_process(int argc, char *argv[], hifiasm_opt_t* asm_opt);
double Get_T(void);

static inline int ha_opt_triobin(const hifiasm_opt_t *opt)
{
	return ((opt->fn_bin_yak[0] && opt->fn_bin_yak[1]) || (opt->fn_bin_list[0] && opt->fn_bin_list[1]));
}

#endif
