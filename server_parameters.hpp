#pragma once


//=========↓↓↓============
// copy your server parameters here!!
const unsigned int __L1cache_size = 1153433;
const unsigned int __L2cache_size = 31457280;
const unsigned int __L3cache_size = 37748736;
const unsigned int __L1cache_size_by_int = __L1cache_size / sizeof(int);
const unsigned int __L2cache_size_by_int = __L2cache_size / sizeof(int);
const unsigned int __L3cache_size_by_int = __L3cache_size / sizeof(int);
const unsigned int __cache_line_size = 64;
const unsigned int __partition_para = 10000;


const double Para_Radix_Flat_Hash_Table_cost = 40.307549; // 1e-9 seconds
const double Para_Radix_LSMapper_build_cost = 19.958672; // 1e-9 seconds
const double Para_Radix_LSMapper_probe_cost = 20.691683; // 1e-9 seconds

const double Para_Rx_Dense = 2.262271; // 1e-9 seconds
const double Para_Rx_Sparse = 3.681726; // 1e-9 seconds
const double Para_Sz_Bitmap = 3.061032; // 1e-9 seconds

const double Para_Sz_mem_seq_read = 0.086263; // 1e-9 seconds
const double Para_Sz_mem_rand_read_1k = 0.937955; // 1e-9 seconds
const double Para_Sz_mem_rand_read_write_1k = 0.539485; // 1e-9 seconds
const double Para_Sz_mem_rand_read_2L2 = 6.489214; // 1e-9 seconds
const double Para_Sz_mem_rand_read_write_2L2 = 6.771252; // 1e-9 seconds
const double Para_Sz_mem_rand_read_05L3 = 3.695732; // 1e-9 seconds
const double Para_Sz_mem_rand_read_write_05L3 = 3.911543; // 1e-9 seconds
const double Para_Sz_mem_rand_read_15L3 = 6.180757; // 1e-9 seconds
const double Para_Sz_mem_rand_read_write_15L3 = 6.467494; // 1e-9 seconds
const double Para_Sz_mem_rand_read_3L3 = 7.636306; // 1e-9 seconds
const double Para_Sz_mem_rand_read_write_3L3 = 8.019107; // 1e-9 seconds
const double Para_Sz_mem_rand_read_10L3 = 7.198486; // 1e-9 seconds
const double Para_Sz_mem_rand_read_write_10L3 = 11.245022; // 1e-9 seconds
//=========↑↑↑============

static double cal_mem_rand_read_cost(int array_size) {
    unsigned int x1 = 1000;
    unsigned int x2 = 2 * __L2cache_size_by_int;
    unsigned int x3 = 0.5 * __L3cache_size_by_int;
    unsigned int x4 = 1.5 * __L3cache_size_by_int;
    unsigned int x5 = 3 * __L3cache_size_by_int;
    unsigned int x6 = 10 * __L3cache_size_by_int;
    if (array_size <= x1) return Para_Sz_mem_rand_read_1k;
    else if (array_size <= x2) {
        return (double)(array_size - x1) / (double)(x2 - x1) * (Para_Sz_mem_rand_read_2L2 - Para_Sz_mem_rand_read_1k) + Para_Sz_mem_rand_read_1k;
    }
    else if (array_size <= x3) {
        return (double)(array_size - x2) / (double)(x3 - x2) * (Para_Sz_mem_rand_read_05L3 - Para_Sz_mem_rand_read_2L2) + Para_Sz_mem_rand_read_2L2;
    }
    else if (array_size <= x4) {
        return (double)(array_size - x3) / (double)(x4 - x3) * (Para_Sz_mem_rand_read_15L3 - Para_Sz_mem_rand_read_05L3) + Para_Sz_mem_rand_read_05L3;
    }
    else if (array_size <= x5) {
        return (double)(array_size - x4) / (double)(x5 - x4) * (Para_Sz_mem_rand_read_3L3 - Para_Sz_mem_rand_read_15L3) + Para_Sz_mem_rand_read_15L3;
    }
    else if (array_size <= x6) {
        return (double)(array_size - x5) / (double)(x6 - x5) * (Para_Sz_mem_rand_read_10L3 - Para_Sz_mem_rand_read_3L3) + Para_Sz_mem_rand_read_3L3;
    }
    else {
        return Para_Sz_mem_rand_read_10L3;
    }
}

static double cal_mem_rand_read_write_cost(int array_size) {
    unsigned int x1 = 1000;
    unsigned int x2 = 2 * __L2cache_size_by_int;
    unsigned int x3 = 0.5 * __L3cache_size_by_int;
    unsigned int x4 = 1.5 * __L3cache_size_by_int;
    unsigned int x5 = 3 * __L3cache_size_by_int;
    unsigned int x6 = 10 * __L3cache_size_by_int;
    if (array_size <= x1) return Para_Sz_mem_rand_read_write_1k;
    else if (array_size <= x2) {
        return (double)(array_size - x1) / (double)(x2 - x1) * (Para_Sz_mem_rand_read_write_2L2 - Para_Sz_mem_rand_read_write_1k) + Para_Sz_mem_rand_read_write_1k;
    }
    else if (array_size <= x3) {
        return (double)(array_size - x2) / (double)(x3 - x2) * (Para_Sz_mem_rand_read_write_05L3 - Para_Sz_mem_rand_read_write_2L2) + Para_Sz_mem_rand_read_write_2L2;
    }
    else if (array_size <= x4) {
        return (double)(array_size - x3) / (double)(x4 - x3) * (Para_Sz_mem_rand_read_write_15L3 - Para_Sz_mem_rand_read_write_05L3) + Para_Sz_mem_rand_read_write_05L3;
    }
    else if (array_size <= x5) {
        return (double)(array_size - x4) / (double)(x5 - x4) * (Para_Sz_mem_rand_read_write_3L3 - Para_Sz_mem_rand_read_write_15L3) + Para_Sz_mem_rand_read_write_15L3;
    }
    else if (array_size <= x6) {
        return (double)(array_size - x5) / (double)(x6 - x5) * (Para_Sz_mem_rand_read_write_10L3 - Para_Sz_mem_rand_read_write_3L3) + Para_Sz_mem_rand_read_write_3L3;
    }
    else {
        return Para_Sz_mem_rand_read_write_10L3;
    }
}