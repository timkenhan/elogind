/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <inttypes.h>

const char *capability_to_name(int id);
#if 0 /// UNNEEDED by elogind
int capability_from_name(const char *name);
int capability_list_length(void);
#endif // 0

int capability_set_to_string_alloc(uint64_t set, char **s);
#if 0 /// UNNEEDED by elogind
int capability_set_from_string(const char *s, uint64_t *set);
#endif // 0
