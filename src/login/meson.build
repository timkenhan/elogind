# SPDX-License-Identifier: LGPL-2.1-or-later

#if 0 /// rename to elogind
# systemd_logind_sources = files(
#         'logind.c',
#         'logind.h',
# )
#else // 0
elogind_sources = files(
        'elogind.c',
        'elogind.h',
        'logind.c',
        'logind.h')
#endif // 0

logind_gperf_c = custom_target(
        'logind_gperf.c',
        input : 'logind-gperf.gperf',
        output : 'logind-gperf.c',
        command : [gperf, '@INPUT@', '--output-file', '@OUTPUT@'])

liblogind_core_sources = files(
        'logind-action.c',
        'logind-action.h',
        'logind-brightness.c',
        'logind-brightness.h',
        'logind-button.c',
        'logind-button.h',
        'logind-core.c',
        'logind-dbus.c',
        'logind-dbus.h',
        'logind-device.c',
        'logind-device.h',
        'logind-inhibit.c',
        'logind-inhibit.h',
        'logind-polkit.c',
        'logind-polkit.h',
        'logind-seat-dbus.c',
        'logind-seat-dbus.h',
        'logind-seat.c',
        'logind-seat.h',
        'logind-session-dbus.c',
        'logind-session-dbus.h',
        'logind-session-device.c',
        'logind-session-device.h',
        'logind-session.c',
        'logind-session.h',
        'logind-user-dbus.c',
        'logind-user-dbus.h',
        'logind-user.c',
        'logind-user.h',
        'logind-utmp.c',
)

#if 1 /// elogind has some additional files:
liblogind_core_sources += [files(
        'user-runtime-dir.c',
        'user-runtime-dir.h',
),
        libcore_sources,
        sleep_files,
        update_utmp_files]
#endif // 1

liblogind_core_sources += [logind_gperf_c]

liblogind_core = static_library(
        'logind-core',
        liblogind_core_sources,
        include_directories : includes,
#if 0 /// elogind needs audit support for utmp inclusion
#         dependencies : libacl,
#         build_by_default : false)
#else // 0
        dependencies : [libacl,
                        libaudit])
#endif // 0

loginctl_sources = files(
        'loginctl.c',
        'sysfs-show.h',
        'sysfs-show.c',
)

#if 1 /// elogind has and needs some additional files:
loginctl_sources += files(
        'eloginctl.c',
        'eloginctl.h',
)
#endif // 1

#if 0 /// elogind calls the functions directly and does not need an extra executable.
# user_runtime_dir_sources = files('user-runtime-dir.c')
#endif // 0

pam_elogind_sym = 'src/login/pam_elogind.sym'
pam_elogind_c = files('pam_elogind.c')

#if 0 /// elogind builds itself unconditionally
# enable_logind = conf.get('ENABLE_LOGIND') == 1
#else // 0
enable_logind = true
#endif // 0

custom_target(
        'logind.conf',
        input : 'logind.conf.in',
        output : 'logind.conf',
        command : [jinja2_cmdline, '@INPUT@', '@OUTPUT@'],
        install : enable_logind and install_sysconfdir_samples and pkgsysconfdir != 'no',
        install_dir : pkgsysconfdir)

custom_target(
        'elogind-user',
        input : 'elogind-user.in',
        output : 'elogind-user',
        command : [jinja2_cmdline, '@INPUT@', '@OUTPUT@'],
        install : enable_logind and pamconfdir != 'no',
        install_dir : pamconfdir)

if enable_logind
        install_data('org.freedesktop.login1.conf',
                     install_dir : dbuspolicydir)
#if 0 /// Works a bit differently here, as elogind allows dbus activation.
#         install_data('org.freedesktop.login1.service',
#                      install_dir : dbussystemservicedir)
#else // 0
        custom_target(
                'org.freedesktop.login1.service',
                input: 'org.freedesktop.login1.service.in',
                output: 'org.freedesktop.login1.service',
                command : [jinja2_cmdline, '@INPUT@', '@OUTPUT@'],
                install: enable_logind,
                install_dir : dbussystemservicedir)
#endif // 0
        install_data('org.freedesktop.login1.policy',
                     install_dir : polkitpolicydir)
endif

############################################################

tests += [
        [files('test-login-shared.c')],

        [files('test-inhibit.c'),
         [], [], [], '', 'manual'],

        [files('test-login-tables.c'),
         [liblogind_core,
          libshared],
         [threads]],

        [files('test-session-properties.c'),
         [], [], [], '', 'manual'],
]
