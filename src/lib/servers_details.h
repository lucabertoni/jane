#ifndef SERVERS_DETAILS_H
#define SERVERS_DETAILS_H

struct HDDPart{
    char *device;
    unsigned int boot;
    unsigned int start;
    unsigned int end;
    unsigned int sectors;
    unsigned int size;
    unsigned int id;
    char *type;
};

struct HardDisk{
    unsigned int size;	// HDD size in bytes
    unsigned int partitions_number;
    struct HDDPart *partitions;
};

/* See /proc/meminfo */
struct Memory{
    unsigned int total;
    unsigned int used;
    unsigned int free;
    unsigned int shared;
    unsigned int buffers;
    unsigned int cached;
};

struct Swap{
    unsigned int total;
    unsigned int used;
    unsigned int free;
};

struct Processor{
    unsigned short int processor_number;
};	// Uncomplete

struct CPUInfo{
    unsigned short int processors_number;
    struct Processor *cpu_processors;
};

struct CPULoad{
    float one_minute_average;
    float five_minute_average;
    float fifteen_minute_average;
};

struct CPU{
    struct CPUInfo *cpu_hw_info;
    struct CPULoad *cpu_load_average;
};

struct ServerHW{
    struct HardDisk *hard_disk_details;
    struct Memory *memory_details;
    struct Swap *swap_details;
    struct CPU *cpu_details;
};

struct Server{
    struct ServerHW *server_hardware;
};

struct Server **servers_details_init(unsigned short int server_count);
void servers_details_free(struct Server **servers, unsigned short int server_count);
struct ServerHW *server_details_serverhw_init();
struct HardDisk *server_details_harddisk_init();
#endif