/*-*- Mode: C; c-basic-offset: 8; indent-tabs-mode: nil -*-*/

#pragma once

/***
  This file is part of systemd.

  Copyright 2013 Lennart Poettering

  systemd is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  systemd is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with systemd; If not, see <http://www.gnu.org/licenses/>.
***/

#include <stdbool.h>

// #include "list.h"
// #include "time-util.h"
#include "logind.h"

// UNNEEDED typedef struct CGroupContext CGroupContext;
// UNNEEDED Stypedef struct CGroupDeviceAllow CGroupDeviceAllow;
// UNNEEDED typedef struct CGroupBlockIODeviceWeight CGroupBlockIODeviceWeight;
// UNNEEDED typedef struct CGroupBlockIODeviceBandwidth CGroupBlockIODeviceBandwidth;

/* Maximum value for fixed (manual) net class ID assignment,
 * and also the value at which the range of automatic assignments starts
 */
// UNNEEDED #define CGROUP_NETCLASS_FIXED_MAX UINT32_C(65535)

// UNNEEDED typedef struct CGroupContext CGroupContext;
// UNNEEDED typedef struct CGroupDeviceAllow CGroupDeviceAllow;
// UNNEEDED typedef struct CGroupBlockIODeviceWeight CGroupBlockIODeviceWeight;
// UNNEEDED typedef struct CGroupBlockIODeviceBandwidth CGroupBlockIODeviceBandwidth;

/// UNNEEDED by elogind
#if 0
typedef enum CGroupDevicePolicy {

        /* When devices listed, will allow those, plus built-in ones,
        if none are listed will allow everything. */
        CGROUP_AUTO,

        /* Everything forbidden, except built-in ones and listed ones. */
        CGROUP_CLOSED,

        /* Everythings forbidden, except for the listed devices */
        CGROUP_STRICT,

        _CGROUP_DEVICE_POLICY_MAX,
        _CGROUP_DEVICE_POLICY_INVALID = -1
} CGroupDevicePolicy;

typedef enum CGroupNetClassType {
        /* Default - do not assign a net class */
        CGROUP_NETCLASS_TYPE_NONE,

        /* Automatically assign a net class */
        CGROUP_NETCLASS_TYPE_AUTO,

        /* Assign the net class that was provided by the user */
        CGROUP_NETCLASS_TYPE_FIXED,
} CGroupNetClassType;

struct CGroupDeviceAllow {
        LIST_FIELDS(CGroupDeviceAllow, device_allow);
        char *path;
        bool r:1;
        bool w:1;
        bool m:1;
};

struct CGroupBlockIODeviceWeight {
        LIST_FIELDS(CGroupBlockIODeviceWeight, device_weights);
        char *path;
        uint64_t weight;
};

struct CGroupBlockIODeviceBandwidth {
        LIST_FIELDS(CGroupBlockIODeviceBandwidth, device_bandwidths);
        char *path;
        uint64_t bandwidth;
        bool read;
};

struct CGroupContext {
        bool cpu_accounting;
        bool blockio_accounting;
        bool memory_accounting;

        uint64_t cpu_shares;
        uint64_t startup_cpu_shares;
        usec_t cpu_quota_per_sec_usec;

        uint64_t blockio_weight;
        uint64_t startup_blockio_weight;
        LIST_HEAD(CGroupBlockIODeviceWeight, blockio_device_weights);
        LIST_HEAD(CGroupBlockIODeviceBandwidth, blockio_device_bandwidths);

        uint64_t memory_limit;

        CGroupDevicePolicy device_policy;
        LIST_HEAD(CGroupDeviceAllow, device_allow);

        CGroupNetClassType netclass_type;
        uint32_t netclass_id;

        uint64_t tasks_max;

        bool delegate;
};
#endif // 0

// #include "unit.h"
// #include "cgroup-util.h"

// UNNNEEDE void cgroup_context_init(CGroupContext *c);
// UNNEEDED void cgroup_context_done(CGroupContext *c);
// UNNEEDED void cgroup_context_dump(CGroupContext *c, FILE* f, const char *prefix);
// UNNEEDED void cgroup_context_apply(CGroupContext *c, CGroupMask mask, const char *path, ManagerState state);

// UNNEEDED CGroupMask cgroup_context_get_mask(CGroupContext *c);

// UNNEEDED void cgroup_context_free_device_allow(CGroupContext *c, CGroupDeviceAllow *a);
// UNNEEDED void cgroup_context_free_blockio_device_weight(CGroupContext *c, CGroupBlockIODeviceWeight *w);
// UNNEEDED void cgroup_context_free_blockio_device_bandwidth(CGroupContext *c, CGroupBlockIODeviceBandwidth *b);

// UNNEEDED CGroupMask unit_get_own_mask(Unit *u);
// UNNEEDED CGroupMask unit_get_siblings_mask(Unit *u);
// UNNEEDED CGroupMask unit_get_members_mask(Unit *u);
// UNNEEDED CGroupMask unit_get_subtree_mask(Unit *u);

// UNNEEDED vCGroupMask unit_get_target_mask(Unit *u);
// UNNEEDED CGroupMask unit_get_enable_mask(Unit *u);

// UNNEEDED void unit_update_cgroup_members_masks(Unit *u);

// UNNEEDED har *unit_default_cgroup_path(Unit *u);
// UNNEEDED int unit_set_cgroup_path(Unit *u, const char *path);

// UNNEEDED int unit_realize_cgroup(Unit *u);
// UNNEEDED void unit_release_cgroup(Unit *u);
// UNNEEDED void unit_prune_cgroup(Unit *u);
// UNNEEDED int unit_watch_cgroup(Unit *u);

// UNNEEDED int unit_attach_pids_to_cgroup(Unit *u);

// UNNEEDED int unit_add_to_netclass_cgroup(Unit *u);
// UNNEEDED int unit_remove_from_netclass_cgroup(Unit *u);

int manager_setup_cgroup(Manager *m);
void manager_shutdown_cgroup(Manager *m, bool delete);

// UNNEEDED unsigned manager_dispatch_cgroup_queue(Manager *m);

// UNNEEDED Unit *manager_get_unit_by_cgroup(Manager *m, const char *cgroup);
// UNNEEDED Unit *manager_get_unit_by_pid_cgroup(Manager *m, pid_t pid);
// UNNEEDED Unit* manager_get_unit_by_pid(Manager *m, pid_t pid);

// UNNEEDED int unit_search_main_pid(Unit *u, pid_t *ret);
// UNNEEDED int unit_watch_all_pids(Unit *u);

// UNNEEDED int unit_get_memory_current(Unit *u, uint64_t *ret);
// UNNEEDED int unit_get_tasks_current(Unit *u, uint64_t *ret);
// UNNEEDED int unit_get_cpu_usage(Unit *u, nsec_t *ret);
// UNNEEDED int unit_reset_cpu_usage(Unit *u);

// UNNEEDED bool unit_cgroup_delegate(Unit *u);

// UNNEEDED int unit_notify_cgroup_empty(Unit *u);
// UNNEEDED int manager_notify_cgroup_empty(Manager *m, const char *group);

// UNNEEDED void unit_invalidate_cgroup(Unit *u, CGroupMask m);

// UNNEEDED void manager_invalidate_startup_units(Manager *m);

// UNNEEDED const char* cgroup_device_policy_to_string(CGroupDevicePolicy i) _const_;
// UNNEEDED CGroupDevicePolicy cgroup_device_policy_from_string(const char *s) _pure_;
