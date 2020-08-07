/*
 * Copyright nPrint 2020
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy
 * of the License at http://www.apache.org/licenses/LICENSE-2.0
 */

#ifndef PCAP_PARSER
#define PCAP_PARSER

#include <netinet/ether.h>

#include <pcap.h>

#include "file_parser.hpp"

/* 
 * Parses a PCAP from a written file
*/

class PCAPParser : public FileParser
{
    public: 
        PCAPParser();
        void process_file();
        void format_and_write_header();
        static void packet_handler(u_char *user_data, const struct pcap_pkthdr* pkthdr,
                                   const u_char* packet);
        int64_t process_timestamp(uint32_t ts);
    private:
        std::vector<std::string> to_fill;
        uint32_t mrt;
};

#endif