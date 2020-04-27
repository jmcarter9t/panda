/*!
 * @file syscall_args.h
 *
 * @brief Macros that declare local variables for system call arguments and
 * copy their values into them. The purpose of this is to avoid having to
 * manually write the boilerplate code that copies arguments from syscall_ctx_t
 * structs to a local variable with a meaningful name.
 *
 * @note: For macros generating c++ references we use `reinterpret_cast`
 * instead of c-style casting. The latter will discard any `const` specifier
 * of the used `ctx` pointer. This happens silently, so it may result in
 * unexpected side-effects.
 * Using `reinterpret_cast` solves this, as it will raise an error if
 * the `const` qualifier is casted away. This also means that we need to
 * have two sets of macros generating references: one for when `ctx` is
 * declared `const syscall_ctx_t *` and one for when it is declared
 * `syscall_ctx_t *`.
 */
#pragma once
#include "panda/plugin.h"

/* ### linux:arm ######################################################## */
// long sys_restart_syscall ['void']
#undef locals_LINUX__ARM_sys_restart_syscall
#if defined(__cplusplus)
#undef references_LINUX__ARM_sys_restart_syscall
#endif

// long sys_exit ['int error_code']
#define locals_LINUX__ARM_sys_exit(ctx, pref) \
	int32_t UNUSED(pref##error_code) = *(int32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_exit(ctx, pref) \
	int32_t &UNUSED(pref##error_code) = *reinterpret_cast<int32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_exit(ctx, pref) \
	const int32_t &UNUSED(pref##error_code) = *reinterpret_cast<const int32_t *>((ctx)->args[0]);
#endif

// long sys_fork ['void']
#undef locals_LINUX__ARM_sys_fork
#if defined(__cplusplus)
#undef references_LINUX__ARM_sys_fork
#endif

// long sys_read ['unsigned int fd', 'char __user *buf', 'size_t count']
#define locals_LINUX__ARM_sys_read(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##buf) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##count) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_read(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##buf) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##count) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_read(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##buf) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##count) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_write ['unsigned int fd', 'const char __user *buf', 'size_t count']
#define locals_LINUX__ARM_sys_write(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##buf) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##count) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_write(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##buf) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##count) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_write(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##buf) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##count) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_open ['const char __user *filename', 'int flags', 'umode_t mode']
#define locals_LINUX__ARM_sys_open(ctx, pref) \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##mode) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_open(ctx, pref) \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##mode) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_open(ctx, pref) \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##mode) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_close ['unsigned int fd']
#define locals_LINUX__ARM_sys_close(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_close(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_close(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_creat ['const char __user *pathname', 'umode_t mode']
#define locals_LINUX__ARM_sys_creat(ctx, pref) \
	uint32_t UNUSED(pref##pathname) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##mode) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_creat(ctx, pref) \
	uint32_t &UNUSED(pref##pathname) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##mode) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_creat(ctx, pref) \
	const uint32_t &UNUSED(pref##pathname) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##mode) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_link ['const char __user *oldname', 'const char __user *newname']
#define locals_LINUX__ARM_sys_link(ctx, pref) \
	uint32_t UNUSED(pref##oldname) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##newname) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_link(ctx, pref) \
	uint32_t &UNUSED(pref##oldname) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##newname) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_link(ctx, pref) \
	const uint32_t &UNUSED(pref##oldname) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##newname) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_unlink ['const char __user *pathname']
#define locals_LINUX__ARM_sys_unlink(ctx, pref) \
	uint32_t UNUSED(pref##pathname) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_unlink(ctx, pref) \
	uint32_t &UNUSED(pref##pathname) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_unlink(ctx, pref) \
	const uint32_t &UNUSED(pref##pathname) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_execve ['const char __user *filename', 'const char __user *const __user *argv', 'const char __user *const __user *envp']
#define locals_LINUX__ARM_sys_execve(ctx, pref) \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##argv) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##envp) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_execve(ctx, pref) \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##argv) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##envp) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_execve(ctx, pref) \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##argv) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##envp) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_chdir ['const char __user *filename']
#define locals_LINUX__ARM_sys_chdir(ctx, pref) \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_chdir(ctx, pref) \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_chdir(ctx, pref) \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_time ['time_t __user *tloc']
#define locals_LINUX__ARM_sys_time(ctx, pref) \
	uint32_t UNUSED(pref##tloc) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_time(ctx, pref) \
	uint32_t &UNUSED(pref##tloc) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_time(ctx, pref) \
	const uint32_t &UNUSED(pref##tloc) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_mknod ['const char __user *filename', 'umode_t mode', 'unsigned dev']
#define locals_LINUX__ARM_sys_mknod(ctx, pref) \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##mode) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##dev) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_mknod(ctx, pref) \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##mode) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##dev) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_mknod(ctx, pref) \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##mode) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##dev) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_chmod ['const char __user *filename', 'umode_t mode']
#define locals_LINUX__ARM_sys_chmod(ctx, pref) \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##mode) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_chmod(ctx, pref) \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##mode) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_chmod(ctx, pref) \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##mode) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_lchown16 ['const char __user *filename', 'old_uid_t user', 'old_gid_t group']
#define locals_LINUX__ARM_sys_lchown16(ctx, pref) \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##user) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##group) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_lchown16(ctx, pref) \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##user) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##group) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_lchown16(ctx, pref) \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##user) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##group) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_lseek ['unsigned int fd', 'off_t offset', 'unsigned int whence']
#define locals_LINUX__ARM_sys_lseek(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##offset) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##whence) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_lseek(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##offset) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##whence) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_lseek(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##offset) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##whence) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_getpid ['void']
#undef locals_LINUX__ARM_sys_getpid
#if defined(__cplusplus)
#undef references_LINUX__ARM_sys_getpid
#endif

// long sys_mount ['char __user *dev_name', 'char __user *dir_name', 'char __user *type', 'unsigned long flags', 'void __user *data']
#define locals_LINUX__ARM_sys_mount(ctx, pref) \
	uint32_t UNUSED(pref##dev_name) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##dir_name) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##type) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##_data) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_mount(ctx, pref) \
	uint32_t &UNUSED(pref##dev_name) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##dir_name) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##type) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##_data) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_mount(ctx, pref) \
	const uint32_t &UNUSED(pref##dev_name) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##dir_name) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##type) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##_data) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_setuid16 ['old_uid_t uid']
#define locals_LINUX__ARM_sys_setuid16(ctx, pref) \
	uint32_t UNUSED(pref##uid) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setuid16(ctx, pref) \
	uint32_t &UNUSED(pref##uid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_setuid16(ctx, pref) \
	const uint32_t &UNUSED(pref##uid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_getuid16 ['void']
#undef locals_LINUX__ARM_sys_getuid16
#if defined(__cplusplus)
#undef references_LINUX__ARM_sys_getuid16
#endif

// long sys_stime ['time_t __user *tptr']
#define locals_LINUX__ARM_sys_stime(ctx, pref) \
	uint32_t UNUSED(pref##tptr) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_stime(ctx, pref) \
	uint32_t &UNUSED(pref##tptr) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_stime(ctx, pref) \
	const uint32_t &UNUSED(pref##tptr) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_ptrace ['long request', 'long pid', 'unsigned long addr', 'unsigned long data']
#define locals_LINUX__ARM_sys_ptrace(ctx, pref) \
	int32_t UNUSED(pref##request) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##pid) = *(int32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##addr) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##_data) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_ptrace(ctx, pref) \
	int32_t &UNUSED(pref##request) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##pid) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##addr) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##_data) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_ptrace(ctx, pref) \
	const int32_t &UNUSED(pref##request) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##pid) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##addr) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##_data) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_alarm ['unsigned int seconds']
#define locals_LINUX__ARM_sys_alarm(ctx, pref) \
	uint32_t UNUSED(pref##seconds) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_alarm(ctx, pref) \
	uint32_t &UNUSED(pref##seconds) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_alarm(ctx, pref) \
	const uint32_t &UNUSED(pref##seconds) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_pause ['void']
#undef locals_LINUX__ARM_sys_pause
#if defined(__cplusplus)
#undef references_LINUX__ARM_sys_pause
#endif

// long sys_utime ['char __user *filename', 'struct utimbuf __user *times']
#define locals_LINUX__ARM_sys_utime(ctx, pref) \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##times) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_utime(ctx, pref) \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##times) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_utime(ctx, pref) \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##times) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_access ['const char __user *filename', 'int mode']
#define locals_LINUX__ARM_sys_access(ctx, pref) \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##mode) = *(int32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_access(ctx, pref) \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##mode) = *reinterpret_cast<int32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_access(ctx, pref) \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##mode) = *reinterpret_cast<const int32_t *>((ctx)->args[1]);
#endif

// long sys_nice ['int increment']
#define locals_LINUX__ARM_sys_nice(ctx, pref) \
	int32_t UNUSED(pref##increment) = *(int32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_nice(ctx, pref) \
	int32_t &UNUSED(pref##increment) = *reinterpret_cast<int32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_nice(ctx, pref) \
	const int32_t &UNUSED(pref##increment) = *reinterpret_cast<const int32_t *>((ctx)->args[0]);
#endif

// long sys_sync ['void']
#undef locals_LINUX__ARM_sys_sync
#if defined(__cplusplus)
#undef references_LINUX__ARM_sys_sync
#endif

// long sys_kill ['pid_t pid', 'int sig']
#define locals_LINUX__ARM_sys_kill(ctx, pref) \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##sig) = *(int32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_kill(ctx, pref) \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##sig) = *reinterpret_cast<int32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_kill(ctx, pref) \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##sig) = *reinterpret_cast<const int32_t *>((ctx)->args[1]);
#endif

// long sys_rename ['const char __user *oldname', 'const char __user *newname']
#define locals_LINUX__ARM_sys_rename(ctx, pref) \
	uint32_t UNUSED(pref##oldname) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##newname) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_rename(ctx, pref) \
	uint32_t &UNUSED(pref##oldname) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##newname) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_rename(ctx, pref) \
	const uint32_t &UNUSED(pref##oldname) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##newname) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_mkdir ['const char __user *pathname', 'umode_t mode']
#define locals_LINUX__ARM_sys_mkdir(ctx, pref) \
	uint32_t UNUSED(pref##pathname) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##mode) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_mkdir(ctx, pref) \
	uint32_t &UNUSED(pref##pathname) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##mode) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_mkdir(ctx, pref) \
	const uint32_t &UNUSED(pref##pathname) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##mode) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_rmdir ['const char __user *pathname']
#define locals_LINUX__ARM_sys_rmdir(ctx, pref) \
	uint32_t UNUSED(pref##pathname) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_rmdir(ctx, pref) \
	uint32_t &UNUSED(pref##pathname) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_rmdir(ctx, pref) \
	const uint32_t &UNUSED(pref##pathname) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_dup ['unsigned int fildes']
#define locals_LINUX__ARM_sys_dup(ctx, pref) \
	uint32_t UNUSED(pref##fildes) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_dup(ctx, pref) \
	uint32_t &UNUSED(pref##fildes) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_dup(ctx, pref) \
	const uint32_t &UNUSED(pref##fildes) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_pipe ['int __user *fildes']
#define locals_LINUX__ARM_sys_pipe(ctx, pref) \
	uint32_t UNUSED(pref##fildes) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_pipe(ctx, pref) \
	uint32_t &UNUSED(pref##fildes) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_pipe(ctx, pref) \
	const uint32_t &UNUSED(pref##fildes) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_times ['struct tms __user *tbuf']
#define locals_LINUX__ARM_sys_times(ctx, pref) \
	uint32_t UNUSED(pref##tbuf) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_times(ctx, pref) \
	uint32_t &UNUSED(pref##tbuf) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_times(ctx, pref) \
	const uint32_t &UNUSED(pref##tbuf) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_brk ['unsigned long brk']
#define locals_LINUX__ARM_sys_brk(ctx, pref) \
	uint32_t UNUSED(pref##brk) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_brk(ctx, pref) \
	uint32_t &UNUSED(pref##brk) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_brk(ctx, pref) \
	const uint32_t &UNUSED(pref##brk) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_setgid16 ['old_gid_t gid']
#define locals_LINUX__ARM_sys_setgid16(ctx, pref) \
	uint32_t UNUSED(pref##gid) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setgid16(ctx, pref) \
	uint32_t &UNUSED(pref##gid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_setgid16(ctx, pref) \
	const uint32_t &UNUSED(pref##gid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_getgid16 ['void']
#undef locals_LINUX__ARM_sys_getgid16
#if defined(__cplusplus)
#undef references_LINUX__ARM_sys_getgid16
#endif

// long sys_geteuid16 ['void']
#undef locals_LINUX__ARM_sys_geteuid16
#if defined(__cplusplus)
#undef references_LINUX__ARM_sys_geteuid16
#endif

// long sys_getegid16 ['void']
#undef locals_LINUX__ARM_sys_getegid16
#if defined(__cplusplus)
#undef references_LINUX__ARM_sys_getegid16
#endif

// long sys_acct ['const char __user *name']
#define locals_LINUX__ARM_sys_acct(ctx, pref) \
	uint32_t UNUSED(pref##name) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_acct(ctx, pref) \
	uint32_t &UNUSED(pref##name) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_acct(ctx, pref) \
	const uint32_t &UNUSED(pref##name) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_umount ['char __user *name', 'int flags']
#define locals_LINUX__ARM_sys_umount(ctx, pref) \
	uint32_t UNUSED(pref##name) = *(uint32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_umount(ctx, pref) \
	uint32_t &UNUSED(pref##name) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_umount(ctx, pref) \
	const uint32_t &UNUSED(pref##name) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[1]);
#endif

// long sys_ioctl ['unsigned int fd', 'unsigned int cmd', 'unsigned long arg']
#define locals_LINUX__ARM_sys_ioctl(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##cmd) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##arg) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_ioctl(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##cmd) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##arg) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_ioctl(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##cmd) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##arg) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_fcntl ['unsigned int fd', 'unsigned int cmd', 'unsigned long arg']
#define locals_LINUX__ARM_sys_fcntl(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##cmd) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##arg) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_fcntl(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##cmd) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##arg) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_fcntl(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##cmd) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##arg) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_setpgid ['pid_t pid', 'pid_t pgid']
#define locals_LINUX__ARM_sys_setpgid(ctx, pref) \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##pgid) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setpgid(ctx, pref) \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##pgid) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_setpgid(ctx, pref) \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##pgid) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_umask ['int mask']
#define locals_LINUX__ARM_sys_umask(ctx, pref) \
	int32_t UNUSED(pref##mask) = *(int32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_umask(ctx, pref) \
	int32_t &UNUSED(pref##mask) = *reinterpret_cast<int32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_umask(ctx, pref) \
	const int32_t &UNUSED(pref##mask) = *reinterpret_cast<const int32_t *>((ctx)->args[0]);
#endif

// long sys_chroot ['const char __user *filename']
#define locals_LINUX__ARM_sys_chroot(ctx, pref) \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_chroot(ctx, pref) \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_chroot(ctx, pref) \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_ustat ['unsigned dev', 'struct ustat __user *ubuf']
#define locals_LINUX__ARM_sys_ustat(ctx, pref) \
	uint32_t UNUSED(pref##dev) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##ubuf) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_ustat(ctx, pref) \
	uint32_t &UNUSED(pref##dev) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##ubuf) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_ustat(ctx, pref) \
	const uint32_t &UNUSED(pref##dev) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##ubuf) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_dup2 ['unsigned int oldfd', 'unsigned int newfd']
#define locals_LINUX__ARM_sys_dup2(ctx, pref) \
	uint32_t UNUSED(pref##oldfd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##newfd) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_dup2(ctx, pref) \
	uint32_t &UNUSED(pref##oldfd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##newfd) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_dup2(ctx, pref) \
	const uint32_t &UNUSED(pref##oldfd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##newfd) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_getppid ['void']
#undef locals_LINUX__ARM_sys_getppid
#if defined(__cplusplus)
#undef references_LINUX__ARM_sys_getppid
#endif

// long sys_getpgrp ['void']
#undef locals_LINUX__ARM_sys_getpgrp
#if defined(__cplusplus)
#undef references_LINUX__ARM_sys_getpgrp
#endif

// long sys_setsid ['void']
#undef locals_LINUX__ARM_sys_setsid
#if defined(__cplusplus)
#undef references_LINUX__ARM_sys_setsid
#endif

// long sys_sigaction ['int', 'const struct old_sigaction __user *', 'struct old_sigaction __user *']
#define locals_LINUX__ARM_sys_sigaction(ctx, pref) \
	int32_t UNUSED(pref##arg0) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##arg1) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##arg2) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sigaction(ctx, pref) \
	int32_t &UNUSED(pref##arg0) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_sigaction(ctx, pref) \
	const int32_t &UNUSED(pref##arg0) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_setreuid16 ['old_uid_t ruid', 'old_uid_t euid']
#define locals_LINUX__ARM_sys_setreuid16(ctx, pref) \
	uint32_t UNUSED(pref##ruid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##euid) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setreuid16(ctx, pref) \
	uint32_t &UNUSED(pref##ruid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##euid) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_setreuid16(ctx, pref) \
	const uint32_t &UNUSED(pref##ruid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##euid) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_setregid16 ['old_gid_t rgid', 'old_gid_t egid']
#define locals_LINUX__ARM_sys_setregid16(ctx, pref) \
	uint32_t UNUSED(pref##rgid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##egid) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setregid16(ctx, pref) \
	uint32_t &UNUSED(pref##rgid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##egid) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_setregid16(ctx, pref) \
	const uint32_t &UNUSED(pref##rgid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##egid) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_sigsuspend ['int unused1', 'int unused2', 'old_sigset_t mask']
#define locals_LINUX__ARM_sys_sigsuspend(ctx, pref) \
	int32_t UNUSED(pref##unused1) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##unused2) = *(int32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##mask) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sigsuspend(ctx, pref) \
	int32_t &UNUSED(pref##unused1) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##unused2) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##mask) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_sigsuspend(ctx, pref) \
	const int32_t &UNUSED(pref##unused1) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##unused2) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##mask) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_sigpending ['old_sigset_t __user *set']
#define locals_LINUX__ARM_sys_sigpending(ctx, pref) \
	uint32_t UNUSED(pref##set) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sigpending(ctx, pref) \
	uint32_t &UNUSED(pref##set) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_sigpending(ctx, pref) \
	const uint32_t &UNUSED(pref##set) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_sethostname ['char __user *name', 'int len']
#define locals_LINUX__ARM_sys_sethostname(ctx, pref) \
	uint32_t UNUSED(pref##name) = *(uint32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##len) = *(int32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sethostname(ctx, pref) \
	uint32_t &UNUSED(pref##name) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##len) = *reinterpret_cast<int32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_sethostname(ctx, pref) \
	const uint32_t &UNUSED(pref##name) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##len) = *reinterpret_cast<const int32_t *>((ctx)->args[1]);
#endif

// long sys_setrlimit ['unsigned int resource', 'struct rlimit __user *rlim']
#define locals_LINUX__ARM_sys_setrlimit(ctx, pref) \
	uint32_t UNUSED(pref##resource) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##rlim) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setrlimit(ctx, pref) \
	uint32_t &UNUSED(pref##resource) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##rlim) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_setrlimit(ctx, pref) \
	const uint32_t &UNUSED(pref##resource) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##rlim) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_getrusage ['int who', 'struct rusage __user *ru']
#define locals_LINUX__ARM_sys_getrusage(ctx, pref) \
	int32_t UNUSED(pref##who) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##ru) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_getrusage(ctx, pref) \
	int32_t &UNUSED(pref##who) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##ru) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_getrusage(ctx, pref) \
	const int32_t &UNUSED(pref##who) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##ru) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_gettimeofday ['struct timeval __user *tv', 'struct timezone __user *tz']
#define locals_LINUX__ARM_sys_gettimeofday(ctx, pref) \
	uint32_t UNUSED(pref##tv) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##tz) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_gettimeofday(ctx, pref) \
	uint32_t &UNUSED(pref##tv) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##tz) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_gettimeofday(ctx, pref) \
	const uint32_t &UNUSED(pref##tv) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##tz) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_settimeofday ['struct timeval __user *tv', 'struct timezone __user *tz']
#define locals_LINUX__ARM_sys_settimeofday(ctx, pref) \
	uint32_t UNUSED(pref##tv) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##tz) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_settimeofday(ctx, pref) \
	uint32_t &UNUSED(pref##tv) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##tz) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_settimeofday(ctx, pref) \
	const uint32_t &UNUSED(pref##tv) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##tz) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_getgroups16 ['int gidsetsize', 'old_gid_t __user *grouplist']
#define locals_LINUX__ARM_sys_getgroups16(ctx, pref) \
	int32_t UNUSED(pref##gidsetsize) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##grouplist) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_getgroups16(ctx, pref) \
	int32_t &UNUSED(pref##gidsetsize) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##grouplist) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_getgroups16(ctx, pref) \
	const int32_t &UNUSED(pref##gidsetsize) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##grouplist) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_setgroups16 ['int gidsetsize', 'old_gid_t __user *grouplist']
#define locals_LINUX__ARM_sys_setgroups16(ctx, pref) \
	int32_t UNUSED(pref##gidsetsize) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##grouplist) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setgroups16(ctx, pref) \
	int32_t &UNUSED(pref##gidsetsize) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##grouplist) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_setgroups16(ctx, pref) \
	const int32_t &UNUSED(pref##gidsetsize) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##grouplist) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_symlink ['const char __user *old', 'const char __user *new']
#define locals_LINUX__ARM_sys_symlink(ctx, pref) \
	uint32_t UNUSED(pref##old) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##_new) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_symlink(ctx, pref) \
	uint32_t &UNUSED(pref##old) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##_new) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_symlink(ctx, pref) \
	const uint32_t &UNUSED(pref##old) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##_new) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_readlink ['const char __user *path', 'char __user *buf', 'int bufsiz']
#define locals_LINUX__ARM_sys_readlink(ctx, pref) \
	uint32_t UNUSED(pref##path) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##buf) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##bufsiz) = *(int32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_readlink(ctx, pref) \
	uint32_t &UNUSED(pref##path) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##buf) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##bufsiz) = *reinterpret_cast<int32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_readlink(ctx, pref) \
	const uint32_t &UNUSED(pref##path) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##buf) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##bufsiz) = *reinterpret_cast<const int32_t *>((ctx)->args[2]);
#endif

// long sys_uselib ['const char __user *library']
#define locals_LINUX__ARM_sys_uselib(ctx, pref) \
	uint32_t UNUSED(pref##library) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_uselib(ctx, pref) \
	uint32_t &UNUSED(pref##library) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_uselib(ctx, pref) \
	const uint32_t &UNUSED(pref##library) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_swapon ['const char __user *specialfile', 'int swap_flags']
#define locals_LINUX__ARM_sys_swapon(ctx, pref) \
	uint32_t UNUSED(pref##specialfile) = *(uint32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##swap_flags) = *(int32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_swapon(ctx, pref) \
	uint32_t &UNUSED(pref##specialfile) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##swap_flags) = *reinterpret_cast<int32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_swapon(ctx, pref) \
	const uint32_t &UNUSED(pref##specialfile) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##swap_flags) = *reinterpret_cast<const int32_t *>((ctx)->args[1]);
#endif

// long sys_reboot ['int magic1', 'int magic2', 'unsigned int cmd', 'void __user *arg']
#define locals_LINUX__ARM_sys_reboot(ctx, pref) \
	int32_t UNUSED(pref##magic1) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##magic2) = *(int32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##cmd) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##arg) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_reboot(ctx, pref) \
	int32_t &UNUSED(pref##magic1) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##magic2) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##cmd) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##arg) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_reboot(ctx, pref) \
	const int32_t &UNUSED(pref##magic1) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##magic2) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##cmd) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##arg) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_munmap ['unsigned long addr', 'size_t len']
#define locals_LINUX__ARM_sys_munmap(ctx, pref) \
	uint32_t UNUSED(pref##addr) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##len) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_munmap(ctx, pref) \
	uint32_t &UNUSED(pref##addr) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##len) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_munmap(ctx, pref) \
	const uint32_t &UNUSED(pref##addr) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##len) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_truncate ['const char __user *path', 'long length']
#define locals_LINUX__ARM_sys_truncate(ctx, pref) \
	uint32_t UNUSED(pref##path) = *(uint32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##length) = *(int32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_truncate(ctx, pref) \
	uint32_t &UNUSED(pref##path) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##length) = *reinterpret_cast<int32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_truncate(ctx, pref) \
	const uint32_t &UNUSED(pref##path) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##length) = *reinterpret_cast<const int32_t *>((ctx)->args[1]);
#endif

// long sys_ftruncate ['unsigned int fd', 'unsigned long length']
#define locals_LINUX__ARM_sys_ftruncate(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##length) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_ftruncate(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##length) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_ftruncate(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##length) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_fchmod ['unsigned int fd', 'umode_t mode']
#define locals_LINUX__ARM_sys_fchmod(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##mode) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_fchmod(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##mode) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_fchmod(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##mode) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_fchown16 ['unsigned int fd', 'old_uid_t user', 'old_gid_t group']
#define locals_LINUX__ARM_sys_fchown16(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##user) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##group) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_fchown16(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##user) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##group) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_fchown16(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##user) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##group) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_getpriority ['int which', 'int who']
#define locals_LINUX__ARM_sys_getpriority(ctx, pref) \
	int32_t UNUSED(pref##which) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##who) = *(int32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_getpriority(ctx, pref) \
	int32_t &UNUSED(pref##which) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##who) = *reinterpret_cast<int32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_getpriority(ctx, pref) \
	const int32_t &UNUSED(pref##which) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##who) = *reinterpret_cast<const int32_t *>((ctx)->args[1]);
#endif

// long sys_setpriority ['int which', 'int who', 'int niceval']
#define locals_LINUX__ARM_sys_setpriority(ctx, pref) \
	int32_t UNUSED(pref##which) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##who) = *(int32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##niceval) = *(int32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setpriority(ctx, pref) \
	int32_t &UNUSED(pref##which) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##who) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##niceval) = *reinterpret_cast<int32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_setpriority(ctx, pref) \
	const int32_t &UNUSED(pref##which) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##who) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##niceval) = *reinterpret_cast<const int32_t *>((ctx)->args[2]);
#endif

// long sys_statfs ['const char __user *path', 'struct statfs __user *buf']
#define locals_LINUX__ARM_sys_statfs(ctx, pref) \
	uint32_t UNUSED(pref##path) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##buf) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_statfs(ctx, pref) \
	uint32_t &UNUSED(pref##path) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##buf) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_statfs(ctx, pref) \
	const uint32_t &UNUSED(pref##path) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##buf) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_fstatfs ['unsigned int fd', 'struct statfs __user *buf']
#define locals_LINUX__ARM_sys_fstatfs(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##buf) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_fstatfs(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##buf) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_fstatfs(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##buf) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_socketcall ['int call', 'unsigned long __user *args']
#define locals_LINUX__ARM_sys_socketcall(ctx, pref) \
	int32_t UNUSED(pref##call) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##args) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_socketcall(ctx, pref) \
	int32_t &UNUSED(pref##call) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##args) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_socketcall(ctx, pref) \
	const int32_t &UNUSED(pref##call) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##args) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_syslog ['int type', 'char __user *buf', 'int len']
#define locals_LINUX__ARM_sys_syslog(ctx, pref) \
	int32_t UNUSED(pref##type) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##buf) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##len) = *(int32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_syslog(ctx, pref) \
	int32_t &UNUSED(pref##type) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##buf) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##len) = *reinterpret_cast<int32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_syslog(ctx, pref) \
	const int32_t &UNUSED(pref##type) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##buf) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##len) = *reinterpret_cast<const int32_t *>((ctx)->args[2]);
#endif

// long sys_setitimer ['int which', 'struct itimerval __user *value', 'struct itimerval __user *ovalue']
#define locals_LINUX__ARM_sys_setitimer(ctx, pref) \
	int32_t UNUSED(pref##which) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##value) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##ovalue) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setitimer(ctx, pref) \
	int32_t &UNUSED(pref##which) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##value) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##ovalue) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_setitimer(ctx, pref) \
	const int32_t &UNUSED(pref##which) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##value) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##ovalue) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_getitimer ['int which', 'struct itimerval __user *value']
#define locals_LINUX__ARM_sys_getitimer(ctx, pref) \
	int32_t UNUSED(pref##which) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##value) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_getitimer(ctx, pref) \
	int32_t &UNUSED(pref##which) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##value) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_getitimer(ctx, pref) \
	const int32_t &UNUSED(pref##which) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##value) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_newstat ['const char __user *filename', 'struct stat __user *statbuf']
#define locals_LINUX__ARM_sys_newstat(ctx, pref) \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##statbuf) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_newstat(ctx, pref) \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##statbuf) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_newstat(ctx, pref) \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##statbuf) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_newlstat ['const char __user *filename', 'struct stat __user *statbuf']
#define locals_LINUX__ARM_sys_newlstat(ctx, pref) \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##statbuf) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_newlstat(ctx, pref) \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##statbuf) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_newlstat(ctx, pref) \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##statbuf) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_newfstat ['unsigned int fd', 'struct stat __user *statbuf']
#define locals_LINUX__ARM_sys_newfstat(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##statbuf) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_newfstat(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##statbuf) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_newfstat(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##statbuf) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_vhangup ['void']
#undef locals_LINUX__ARM_sys_vhangup
#if defined(__cplusplus)
#undef references_LINUX__ARM_sys_vhangup
#endif

// long sys_wait4 ['pid_t pid', 'int __user *stat_addr', 'int options', 'struct rusage __user *ru']
#define locals_LINUX__ARM_sys_wait4(ctx, pref) \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##stat_addr) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##options) = *(int32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##ru) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_wait4(ctx, pref) \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##stat_addr) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##options) = *reinterpret_cast<int32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##ru) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_wait4(ctx, pref) \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##stat_addr) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##options) = *reinterpret_cast<const int32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##ru) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_swapoff ['const char __user *specialfile']
#define locals_LINUX__ARM_sys_swapoff(ctx, pref) \
	uint32_t UNUSED(pref##specialfile) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_swapoff(ctx, pref) \
	uint32_t &UNUSED(pref##specialfile) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_swapoff(ctx, pref) \
	const uint32_t &UNUSED(pref##specialfile) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_sysinfo ['struct sysinfo __user *info']
#define locals_LINUX__ARM_sys_sysinfo(ctx, pref) \
	uint32_t UNUSED(pref##info) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sysinfo(ctx, pref) \
	uint32_t &UNUSED(pref##info) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_sysinfo(ctx, pref) \
	const uint32_t &UNUSED(pref##info) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_ipc ['unsigned int call', 'int first', 'unsigned long second', 'unsigned long third', 'void __user *ptr', 'long fifth']
#define locals_LINUX__ARM_sys_ipc(ctx, pref) \
	uint32_t UNUSED(pref##call) = *(uint32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##first) = *(int32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##second) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##third) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##ptr) = *(uint32_t *)((ctx)->args[4]); \
	int32_t UNUSED(pref##fifth) = *(int32_t *)((ctx)->args[5]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_ipc(ctx, pref) \
	uint32_t &UNUSED(pref##call) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##first) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##second) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##third) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##ptr) = *reinterpret_cast<uint32_t *>((ctx)->args[4]); \
	int32_t &UNUSED(pref##fifth) = *reinterpret_cast<int32_t *>((ctx)->args[5]);
#define creferences_LINUX__ARM_sys_ipc(ctx, pref) \
	const uint32_t &UNUSED(pref##call) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##first) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##second) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##third) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##ptr) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]); \
	const int32_t &UNUSED(pref##fifth) = *reinterpret_cast<const int32_t *>((ctx)->args[5]);
#endif

// long sys_fsync ['unsigned int fd']
#define locals_LINUX__ARM_sys_fsync(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_fsync(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_fsync(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// int sys_sigreturn ['struct pt_regs *regs']
#define locals_LINUX__ARM_sys_sigreturn(ctx, pref) \
	uint32_t UNUSED(pref##regs) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sigreturn(ctx, pref) \
	uint32_t &UNUSED(pref##regs) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_sigreturn(ctx, pref) \
	const uint32_t &UNUSED(pref##regs) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_clone ['unsigned long', 'unsigned long', 'int __user *', 'int __user *', 'unsigned long']
#define locals_LINUX__ARM_sys_clone(ctx, pref) \
	uint32_t UNUSED(pref##arg0) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##arg1) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##arg2) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##arg3) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##arg4) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_clone(ctx, pref) \
	uint32_t &UNUSED(pref##arg0) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##arg3) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##arg4) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_clone(ctx, pref) \
	const uint32_t &UNUSED(pref##arg0) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##arg3) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##arg4) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_setdomainname ['char __user *name', 'int len']
#define locals_LINUX__ARM_sys_setdomainname(ctx, pref) \
	uint32_t UNUSED(pref##name) = *(uint32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##len) = *(int32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setdomainname(ctx, pref) \
	uint32_t &UNUSED(pref##name) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##len) = *reinterpret_cast<int32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_setdomainname(ctx, pref) \
	const uint32_t &UNUSED(pref##name) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##len) = *reinterpret_cast<const int32_t *>((ctx)->args[1]);
#endif

// long sys_newuname ['struct new_utsname __user *name']
#define locals_LINUX__ARM_sys_newuname(ctx, pref) \
	uint32_t UNUSED(pref##name) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_newuname(ctx, pref) \
	uint32_t &UNUSED(pref##name) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_newuname(ctx, pref) \
	const uint32_t &UNUSED(pref##name) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_adjtimex ['struct timex __user *txc_p']
#define locals_LINUX__ARM_sys_adjtimex(ctx, pref) \
	uint32_t UNUSED(pref##txc_p) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_adjtimex(ctx, pref) \
	uint32_t &UNUSED(pref##txc_p) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_adjtimex(ctx, pref) \
	const uint32_t &UNUSED(pref##txc_p) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_mprotect ['unsigned long start', 'size_t len', 'unsigned long prot']
#define locals_LINUX__ARM_sys_mprotect(ctx, pref) \
	uint32_t UNUSED(pref##start) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##len) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##prot) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_mprotect(ctx, pref) \
	uint32_t &UNUSED(pref##start) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##len) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##prot) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_mprotect(ctx, pref) \
	const uint32_t &UNUSED(pref##start) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##len) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##prot) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_sigprocmask ['int how', 'old_sigset_t __user *set', 'old_sigset_t __user *oset']
#define locals_LINUX__ARM_sys_sigprocmask(ctx, pref) \
	int32_t UNUSED(pref##how) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##set) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##oset) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sigprocmask(ctx, pref) \
	int32_t &UNUSED(pref##how) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##set) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##oset) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_sigprocmask(ctx, pref) \
	const int32_t &UNUSED(pref##how) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##set) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##oset) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_init_module ['void __user *umod', 'unsigned long len', 'const char __user *uargs']
#define locals_LINUX__ARM_sys_init_module(ctx, pref) \
	uint32_t UNUSED(pref##umod) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##len) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##uargs) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_init_module(ctx, pref) \
	uint32_t &UNUSED(pref##umod) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##len) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##uargs) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_init_module(ctx, pref) \
	const uint32_t &UNUSED(pref##umod) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##len) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##uargs) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_delete_module ['const char __user *name_user', 'unsigned int flags']
#define locals_LINUX__ARM_sys_delete_module(ctx, pref) \
	uint32_t UNUSED(pref##name_user) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_delete_module(ctx, pref) \
	uint32_t &UNUSED(pref##name_user) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_delete_module(ctx, pref) \
	const uint32_t &UNUSED(pref##name_user) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_quotactl ['unsigned int cmd', 'const char __user *special', 'qid_t id', 'void __user *addr']
#define locals_LINUX__ARM_sys_quotactl(ctx, pref) \
	uint32_t UNUSED(pref##cmd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##special) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##id) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##addr) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_quotactl(ctx, pref) \
	uint32_t &UNUSED(pref##cmd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##special) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##id) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##addr) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_quotactl(ctx, pref) \
	const uint32_t &UNUSED(pref##cmd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##special) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##id) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##addr) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_getpgid ['pid_t pid']
#define locals_LINUX__ARM_sys_getpgid(ctx, pref) \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_getpgid(ctx, pref) \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_getpgid(ctx, pref) \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_fchdir ['unsigned int fd']
#define locals_LINUX__ARM_sys_fchdir(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_fchdir(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_fchdir(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_bdflush ['int func', 'long data']
#define locals_LINUX__ARM_sys_bdflush(ctx, pref) \
	int32_t UNUSED(pref##func) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##_data) = *(int32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_bdflush(ctx, pref) \
	int32_t &UNUSED(pref##func) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##_data) = *reinterpret_cast<int32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_bdflush(ctx, pref) \
	const int32_t &UNUSED(pref##func) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##_data) = *reinterpret_cast<const int32_t *>((ctx)->args[1]);
#endif

// long sys_sysfs ['int option', 'unsigned long arg1', 'unsigned long arg2']
#define locals_LINUX__ARM_sys_sysfs(ctx, pref) \
	int32_t UNUSED(pref##option) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##arg1) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##arg2) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sysfs(ctx, pref) \
	int32_t &UNUSED(pref##option) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_sysfs(ctx, pref) \
	const int32_t &UNUSED(pref##option) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_personality ['unsigned int personality']
#define locals_LINUX__ARM_sys_personality(ctx, pref) \
	uint32_t UNUSED(pref##personality) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_personality(ctx, pref) \
	uint32_t &UNUSED(pref##personality) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_personality(ctx, pref) \
	const uint32_t &UNUSED(pref##personality) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_setfsuid16 ['old_uid_t uid']
#define locals_LINUX__ARM_sys_setfsuid16(ctx, pref) \
	uint32_t UNUSED(pref##uid) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setfsuid16(ctx, pref) \
	uint32_t &UNUSED(pref##uid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_setfsuid16(ctx, pref) \
	const uint32_t &UNUSED(pref##uid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_setfsgid16 ['old_gid_t gid']
#define locals_LINUX__ARM_sys_setfsgid16(ctx, pref) \
	uint32_t UNUSED(pref##gid) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setfsgid16(ctx, pref) \
	uint32_t &UNUSED(pref##gid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_setfsgid16(ctx, pref) \
	const uint32_t &UNUSED(pref##gid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_llseek ['unsigned int fd', 'unsigned long offset_high', 'unsigned long offset_low', 'loff_t __user *result', 'unsigned int whence']
#define locals_LINUX__ARM_sys_llseek(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##offset_high) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##offset_low) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##result) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##whence) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_llseek(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##offset_high) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##offset_low) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##result) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##whence) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_llseek(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##offset_high) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##offset_low) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##result) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##whence) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_getdents ['unsigned int fd', 'struct linux_dirent __user *dirent', 'unsigned int count']
#define locals_LINUX__ARM_sys_getdents(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##dirent) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##count) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_getdents(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##dirent) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##count) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_getdents(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##dirent) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##count) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_select ['int n', 'fd_set __user *inp', 'fd_set __user *outp', 'fd_set __user *exp', 'struct timeval __user *tvp']
#define locals_LINUX__ARM_sys_select(ctx, pref) \
	int32_t UNUSED(pref##n) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##inp) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##outp) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##exp) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##tvp) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_select(ctx, pref) \
	int32_t &UNUSED(pref##n) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##inp) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##outp) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##exp) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##tvp) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_select(ctx, pref) \
	const int32_t &UNUSED(pref##n) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##inp) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##outp) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##exp) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##tvp) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_flock ['unsigned int fd', 'unsigned int cmd']
#define locals_LINUX__ARM_sys_flock(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##cmd) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_flock(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##cmd) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_flock(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##cmd) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_msync ['unsigned long start', 'size_t len', 'int flags']
#define locals_LINUX__ARM_sys_msync(ctx, pref) \
	uint32_t UNUSED(pref##start) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##len) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_msync(ctx, pref) \
	uint32_t &UNUSED(pref##start) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##len) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_msync(ctx, pref) \
	const uint32_t &UNUSED(pref##start) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##len) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[2]);
#endif

// long sys_readv ['unsigned long fd', 'const struct iovec __user *vec', 'unsigned long vlen']
#define locals_LINUX__ARM_sys_readv(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##vec) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##vlen) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_readv(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##vec) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##vlen) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_readv(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##vec) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##vlen) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_writev ['unsigned long fd', 'const struct iovec __user *vec', 'unsigned long vlen']
#define locals_LINUX__ARM_sys_writev(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##vec) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##vlen) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_writev(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##vec) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##vlen) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_writev(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##vec) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##vlen) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_getsid ['pid_t pid']
#define locals_LINUX__ARM_sys_getsid(ctx, pref) \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_getsid(ctx, pref) \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_getsid(ctx, pref) \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_fdatasync ['unsigned int fd']
#define locals_LINUX__ARM_sys_fdatasync(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_fdatasync(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_fdatasync(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_sysctl ['struct __sysctl_args __user *args']
#define locals_LINUX__ARM_sys_sysctl(ctx, pref) \
	uint32_t UNUSED(pref##args) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sysctl(ctx, pref) \
	uint32_t &UNUSED(pref##args) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_sysctl(ctx, pref) \
	const uint32_t &UNUSED(pref##args) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_mlock ['unsigned long start', 'size_t len']
#define locals_LINUX__ARM_sys_mlock(ctx, pref) \
	uint32_t UNUSED(pref##start) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##len) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_mlock(ctx, pref) \
	uint32_t &UNUSED(pref##start) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##len) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_mlock(ctx, pref) \
	const uint32_t &UNUSED(pref##start) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##len) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_munlock ['unsigned long start', 'size_t len']
#define locals_LINUX__ARM_sys_munlock(ctx, pref) \
	uint32_t UNUSED(pref##start) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##len) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_munlock(ctx, pref) \
	uint32_t &UNUSED(pref##start) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##len) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_munlock(ctx, pref) \
	const uint32_t &UNUSED(pref##start) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##len) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_mlockall ['int flags']
#define locals_LINUX__ARM_sys_mlockall(ctx, pref) \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_mlockall(ctx, pref) \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_mlockall(ctx, pref) \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[0]);
#endif

// long sys_munlockall ['void']
#undef locals_LINUX__ARM_sys_munlockall
#if defined(__cplusplus)
#undef references_LINUX__ARM_sys_munlockall
#endif

// long sys_sched_setparam ['pid_t pid', 'struct sched_param __user *param']
#define locals_LINUX__ARM_sys_sched_setparam(ctx, pref) \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##param) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sched_setparam(ctx, pref) \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##param) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_sched_setparam(ctx, pref) \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##param) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_sched_getparam ['pid_t pid', 'struct sched_param __user *param']
#define locals_LINUX__ARM_sys_sched_getparam(ctx, pref) \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##param) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sched_getparam(ctx, pref) \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##param) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_sched_getparam(ctx, pref) \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##param) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_sched_setscheduler ['pid_t pid', 'int policy', 'struct sched_param __user *param']
#define locals_LINUX__ARM_sys_sched_setscheduler(ctx, pref) \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##policy) = *(int32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##param) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sched_setscheduler(ctx, pref) \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##policy) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##param) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_sched_setscheduler(ctx, pref) \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##policy) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##param) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_sched_getscheduler ['pid_t pid']
#define locals_LINUX__ARM_sys_sched_getscheduler(ctx, pref) \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sched_getscheduler(ctx, pref) \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_sched_getscheduler(ctx, pref) \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_sched_yield ['void']
#undef locals_LINUX__ARM_sys_sched_yield
#if defined(__cplusplus)
#undef references_LINUX__ARM_sys_sched_yield
#endif

// long sys_sched_get_priority_max ['int policy']
#define locals_LINUX__ARM_sys_sched_get_priority_max(ctx, pref) \
	int32_t UNUSED(pref##policy) = *(int32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sched_get_priority_max(ctx, pref) \
	int32_t &UNUSED(pref##policy) = *reinterpret_cast<int32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_sched_get_priority_max(ctx, pref) \
	const int32_t &UNUSED(pref##policy) = *reinterpret_cast<const int32_t *>((ctx)->args[0]);
#endif

// long sys_sched_get_priority_min ['int policy']
#define locals_LINUX__ARM_sys_sched_get_priority_min(ctx, pref) \
	int32_t UNUSED(pref##policy) = *(int32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sched_get_priority_min(ctx, pref) \
	int32_t &UNUSED(pref##policy) = *reinterpret_cast<int32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_sched_get_priority_min(ctx, pref) \
	const int32_t &UNUSED(pref##policy) = *reinterpret_cast<const int32_t *>((ctx)->args[0]);
#endif

// long sys_sched_rr_get_interval ['pid_t pid', 'struct timespec __user *interval']
#define locals_LINUX__ARM_sys_sched_rr_get_interval(ctx, pref) \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##interval) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sched_rr_get_interval(ctx, pref) \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##interval) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_sched_rr_get_interval(ctx, pref) \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##interval) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_nanosleep ['struct timespec __user *rqtp', 'struct timespec __user *rmtp']
#define locals_LINUX__ARM_sys_nanosleep(ctx, pref) \
	uint32_t UNUSED(pref##rqtp) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##rmtp) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_nanosleep(ctx, pref) \
	uint32_t &UNUSED(pref##rqtp) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##rmtp) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_nanosleep(ctx, pref) \
	const uint32_t &UNUSED(pref##rqtp) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##rmtp) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_mremap ['unsigned long addr', 'unsigned long old_len', 'unsigned long new_len', 'unsigned long flags', 'unsigned long new_addr']
#define locals_LINUX__ARM_sys_mremap(ctx, pref) \
	uint32_t UNUSED(pref##addr) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##old_len) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##new_len) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##new_addr) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_mremap(ctx, pref) \
	uint32_t &UNUSED(pref##addr) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##old_len) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##new_len) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##new_addr) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_mremap(ctx, pref) \
	const uint32_t &UNUSED(pref##addr) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##old_len) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##new_len) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##new_addr) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_setresuid16 ['old_uid_t ruid', 'old_uid_t euid', 'old_uid_t suid']
#define locals_LINUX__ARM_sys_setresuid16(ctx, pref) \
	uint32_t UNUSED(pref##ruid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##euid) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##suid) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setresuid16(ctx, pref) \
	uint32_t &UNUSED(pref##ruid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##euid) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##suid) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_setresuid16(ctx, pref) \
	const uint32_t &UNUSED(pref##ruid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##euid) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##suid) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_getresuid16 ['old_uid_t __user *ruid', 'old_uid_t __user *euid', 'old_uid_t __user *suid']
#define locals_LINUX__ARM_sys_getresuid16(ctx, pref) \
	uint32_t UNUSED(pref##ruid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##euid) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##suid) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_getresuid16(ctx, pref) \
	uint32_t &UNUSED(pref##ruid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##euid) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##suid) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_getresuid16(ctx, pref) \
	const uint32_t &UNUSED(pref##ruid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##euid) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##suid) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_poll ['struct pollfd __user *ufds', 'unsigned int nfds', 'int timeout']
#define locals_LINUX__ARM_sys_poll(ctx, pref) \
	uint32_t UNUSED(pref##ufds) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##nfds) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##timeout) = *(int32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_poll(ctx, pref) \
	uint32_t &UNUSED(pref##ufds) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##nfds) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##timeout) = *reinterpret_cast<int32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_poll(ctx, pref) \
	const uint32_t &UNUSED(pref##ufds) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##nfds) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##timeout) = *reinterpret_cast<const int32_t *>((ctx)->args[2]);
#endif

// long sys_setresgid16 ['old_gid_t rgid', 'old_gid_t egid', 'old_gid_t sgid']
#define locals_LINUX__ARM_sys_setresgid16(ctx, pref) \
	uint32_t UNUSED(pref##rgid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##egid) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##sgid) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setresgid16(ctx, pref) \
	uint32_t &UNUSED(pref##rgid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##egid) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##sgid) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_setresgid16(ctx, pref) \
	const uint32_t &UNUSED(pref##rgid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##egid) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##sgid) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_getresgid16 ['old_gid_t __user *rgid', 'old_gid_t __user *egid', 'old_gid_t __user *sgid']
#define locals_LINUX__ARM_sys_getresgid16(ctx, pref) \
	uint32_t UNUSED(pref##rgid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##egid) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##sgid) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_getresgid16(ctx, pref) \
	uint32_t &UNUSED(pref##rgid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##egid) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##sgid) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_getresgid16(ctx, pref) \
	const uint32_t &UNUSED(pref##rgid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##egid) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##sgid) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_prctl ['int option', 'unsigned long arg2', 'unsigned long arg3', 'unsigned long arg4', 'unsigned long arg5']
#define locals_LINUX__ARM_sys_prctl(ctx, pref) \
	int32_t UNUSED(pref##option) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##arg2) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##arg3) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##arg4) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##arg5) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_prctl(ctx, pref) \
	int32_t &UNUSED(pref##option) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##arg3) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##arg4) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##arg5) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_prctl(ctx, pref) \
	const int32_t &UNUSED(pref##option) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##arg3) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##arg4) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##arg5) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// int sys_rt_sigreturn ['struct pt_regs *regs']
#define locals_LINUX__ARM_sys_rt_sigreturn(ctx, pref) \
	uint32_t UNUSED(pref##regs) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_rt_sigreturn(ctx, pref) \
	uint32_t &UNUSED(pref##regs) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_rt_sigreturn(ctx, pref) \
	const uint32_t &UNUSED(pref##regs) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_rt_sigaction ['int', 'const struct sigaction __user *', 'struct sigaction __user *', 'size_t']
#define locals_LINUX__ARM_sys_rt_sigaction(ctx, pref) \
	int32_t UNUSED(pref##arg0) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##arg1) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##arg2) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##arg3) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_rt_sigaction(ctx, pref) \
	int32_t &UNUSED(pref##arg0) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##arg3) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_rt_sigaction(ctx, pref) \
	const int32_t &UNUSED(pref##arg0) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##arg3) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_rt_sigprocmask ['int how', 'sigset_t __user *set', 'sigset_t __user *oset', 'size_t sigsetsize']
#define locals_LINUX__ARM_sys_rt_sigprocmask(ctx, pref) \
	int32_t UNUSED(pref##how) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##set) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##oset) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##sigsetsize) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_rt_sigprocmask(ctx, pref) \
	int32_t &UNUSED(pref##how) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##set) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##oset) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##sigsetsize) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_rt_sigprocmask(ctx, pref) \
	const int32_t &UNUSED(pref##how) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##set) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##oset) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##sigsetsize) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_rt_sigpending ['sigset_t __user *set', 'size_t sigsetsize']
#define locals_LINUX__ARM_sys_rt_sigpending(ctx, pref) \
	uint32_t UNUSED(pref##set) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##sigsetsize) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_rt_sigpending(ctx, pref) \
	uint32_t &UNUSED(pref##set) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##sigsetsize) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_rt_sigpending(ctx, pref) \
	const uint32_t &UNUSED(pref##set) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##sigsetsize) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_rt_sigtimedwait ['const sigset_t __user *uthese', 'siginfo_t __user *uinfo', 'const struct timespec __user *uts', 'size_t sigsetsize']
#define locals_LINUX__ARM_sys_rt_sigtimedwait(ctx, pref) \
	uint32_t UNUSED(pref##uthese) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##uinfo) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##uts) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##sigsetsize) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_rt_sigtimedwait(ctx, pref) \
	uint32_t &UNUSED(pref##uthese) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##uinfo) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##uts) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##sigsetsize) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_rt_sigtimedwait(ctx, pref) \
	const uint32_t &UNUSED(pref##uthese) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##uinfo) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##uts) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##sigsetsize) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_rt_sigqueueinfo ['pid_t pid', 'int sig', 'siginfo_t __user *uinfo']
#define locals_LINUX__ARM_sys_rt_sigqueueinfo(ctx, pref) \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##sig) = *(int32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##uinfo) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_rt_sigqueueinfo(ctx, pref) \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##sig) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##uinfo) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_rt_sigqueueinfo(ctx, pref) \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##sig) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##uinfo) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_rt_sigsuspend ['sigset_t __user *unewset', 'size_t sigsetsize']
#define locals_LINUX__ARM_sys_rt_sigsuspend(ctx, pref) \
	uint32_t UNUSED(pref##unewset) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##sigsetsize) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_rt_sigsuspend(ctx, pref) \
	uint32_t &UNUSED(pref##unewset) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##sigsetsize) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_rt_sigsuspend(ctx, pref) \
	const uint32_t &UNUSED(pref##unewset) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##sigsetsize) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_pread64 ['unsigned int fd', 'char __user *buf', 'size_t count', 'loff_t pos']
#define locals_LINUX__ARM_sys_pread64(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##buf) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##count) = *(uint32_t *)((ctx)->args[2]); \
	uint64_t UNUSED(pref##pos) = *(uint64_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_pread64(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##buf) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##count) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint64_t &UNUSED(pref##pos) = *reinterpret_cast<uint64_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_pread64(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##buf) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##count) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint64_t &UNUSED(pref##pos) = *reinterpret_cast<const uint64_t *>((ctx)->args[3]);
#endif

// long sys_pwrite64 ['unsigned int fd', 'const char __user *buf', 'size_t count', 'loff_t pos']
#define locals_LINUX__ARM_sys_pwrite64(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##buf) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##count) = *(uint32_t *)((ctx)->args[2]); \
	uint64_t UNUSED(pref##pos) = *(uint64_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_pwrite64(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##buf) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##count) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint64_t &UNUSED(pref##pos) = *reinterpret_cast<uint64_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_pwrite64(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##buf) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##count) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint64_t &UNUSED(pref##pos) = *reinterpret_cast<const uint64_t *>((ctx)->args[3]);
#endif

// long sys_chown16 ['const char __user *filename', 'old_uid_t user', 'old_gid_t group']
#define locals_LINUX__ARM_sys_chown16(ctx, pref) \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##user) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##group) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_chown16(ctx, pref) \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##user) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##group) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_chown16(ctx, pref) \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##user) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##group) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_getcwd ['char __user *buf', 'unsigned long size']
#define locals_LINUX__ARM_sys_getcwd(ctx, pref) \
	uint32_t UNUSED(pref##buf) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##size) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_getcwd(ctx, pref) \
	uint32_t &UNUSED(pref##buf) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##size) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_getcwd(ctx, pref) \
	const uint32_t &UNUSED(pref##buf) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##size) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_capget ['cap_user_header_t header', 'cap_user_data_t dataptr']
#define locals_LINUX__ARM_sys_capget(ctx, pref) \
	uint32_t UNUSED(pref##header) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##dataptr) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_capget(ctx, pref) \
	uint32_t &UNUSED(pref##header) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##dataptr) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_capget(ctx, pref) \
	const uint32_t &UNUSED(pref##header) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##dataptr) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_capset ['cap_user_header_t header', 'const cap_user_data_t data']
#define locals_LINUX__ARM_sys_capset(ctx, pref) \
	uint32_t UNUSED(pref##header) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##_data) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_capset(ctx, pref) \
	uint32_t &UNUSED(pref##header) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##_data) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_capset(ctx, pref) \
	const uint32_t &UNUSED(pref##header) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##_data) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_sigaltstack ['const struct sigaltstack __user *uss', 'struct sigaltstack __user *uoss']
#define locals_LINUX__ARM_sys_sigaltstack(ctx, pref) \
	uint32_t UNUSED(pref##uss) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##uoss) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sigaltstack(ctx, pref) \
	uint32_t &UNUSED(pref##uss) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##uoss) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_sigaltstack(ctx, pref) \
	const uint32_t &UNUSED(pref##uss) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##uoss) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_sendfile ['int out_fd', 'int in_fd', 'off_t __user *offset', 'size_t count']
#define locals_LINUX__ARM_sys_sendfile(ctx, pref) \
	int32_t UNUSED(pref##out_fd) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##in_fd) = *(int32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##offset) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##count) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sendfile(ctx, pref) \
	int32_t &UNUSED(pref##out_fd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##in_fd) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##offset) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##count) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_sendfile(ctx, pref) \
	const int32_t &UNUSED(pref##out_fd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##in_fd) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##offset) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##count) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_vfork ['void']
#undef locals_LINUX__ARM_sys_vfork
#if defined(__cplusplus)
#undef references_LINUX__ARM_sys_vfork
#endif

// long sys_getrlimit ['unsigned int resource', 'struct rlimit __user *rlim']
#define locals_LINUX__ARM_sys_getrlimit(ctx, pref) \
	uint32_t UNUSED(pref##resource) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##rlim) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_getrlimit(ctx, pref) \
	uint32_t &UNUSED(pref##resource) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##rlim) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_getrlimit(ctx, pref) \
	const uint32_t &UNUSED(pref##resource) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##rlim) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long do_mmap2 ['unsigned long addr', 'unsigned long len', 'unsigned long prot', 'unsigned long flags', 'unsigned long fd', 'unsigned long pgoff']
#define locals_LINUX__ARM_do_mmap2(ctx, pref) \
	uint32_t UNUSED(pref##addr) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##len) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##prot) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[4]); \
	uint32_t UNUSED(pref##pgoff) = *(uint32_t *)((ctx)->args[5]);
#if defined(__cplusplus)
#define references_LINUX__ARM_do_mmap2(ctx, pref) \
	uint32_t &UNUSED(pref##addr) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##len) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##prot) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[4]); \
	uint32_t &UNUSED(pref##pgoff) = *reinterpret_cast<uint32_t *>((ctx)->args[5]);
#define creferences_LINUX__ARM_do_mmap2(ctx, pref) \
	const uint32_t &UNUSED(pref##addr) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##len) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##prot) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]); \
	const uint32_t &UNUSED(pref##pgoff) = *reinterpret_cast<const uint32_t *>((ctx)->args[5]);
#endif

// long sys_truncate64 ['const char __user *path', 'loff_t length']
#define locals_LINUX__ARM_sys_truncate64(ctx, pref) \
	uint32_t UNUSED(pref##path) = *(uint32_t *)((ctx)->args[0]); \
	uint64_t UNUSED(pref##length) = *(uint64_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_truncate64(ctx, pref) \
	uint32_t &UNUSED(pref##path) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint64_t &UNUSED(pref##length) = *reinterpret_cast<uint64_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_truncate64(ctx, pref) \
	const uint32_t &UNUSED(pref##path) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint64_t &UNUSED(pref##length) = *reinterpret_cast<const uint64_t *>((ctx)->args[1]);
#endif

// long sys_ftruncate64 ['unsigned int fd', 'loff_t length']
#define locals_LINUX__ARM_sys_ftruncate64(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint64_t UNUSED(pref##length) = *(uint64_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_ftruncate64(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint64_t &UNUSED(pref##length) = *reinterpret_cast<uint64_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_ftruncate64(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint64_t &UNUSED(pref##length) = *reinterpret_cast<const uint64_t *>((ctx)->args[1]);
#endif

// long sys_stat64 ['const char __user *filename', 'struct stat64 __user *statbuf']
#define locals_LINUX__ARM_sys_stat64(ctx, pref) \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##statbuf) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_stat64(ctx, pref) \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##statbuf) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_stat64(ctx, pref) \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##statbuf) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_lstat64 ['const char __user *filename', 'struct stat64 __user *statbuf']
#define locals_LINUX__ARM_sys_lstat64(ctx, pref) \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##statbuf) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_lstat64(ctx, pref) \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##statbuf) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_lstat64(ctx, pref) \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##statbuf) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_fstat64 ['unsigned long fd', 'struct stat64 __user *statbuf']
#define locals_LINUX__ARM_sys_fstat64(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##statbuf) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_fstat64(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##statbuf) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_fstat64(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##statbuf) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_lchown ['const char __user *filename', 'uid_t user', 'gid_t group']
#define locals_LINUX__ARM_sys_lchown(ctx, pref) \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##user) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##group) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_lchown(ctx, pref) \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##user) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##group) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_lchown(ctx, pref) \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##user) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##group) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_getuid ['void']
#undef locals_LINUX__ARM_sys_getuid
#if defined(__cplusplus)
#undef references_LINUX__ARM_sys_getuid
#endif

// long sys_getgid ['void']
#undef locals_LINUX__ARM_sys_getgid
#if defined(__cplusplus)
#undef references_LINUX__ARM_sys_getgid
#endif

// long sys_geteuid ['void']
#undef locals_LINUX__ARM_sys_geteuid
#if defined(__cplusplus)
#undef references_LINUX__ARM_sys_geteuid
#endif

// long sys_getegid ['void']
#undef locals_LINUX__ARM_sys_getegid
#if defined(__cplusplus)
#undef references_LINUX__ARM_sys_getegid
#endif

// long sys_setreuid ['uid_t ruid', 'uid_t euid']
#define locals_LINUX__ARM_sys_setreuid(ctx, pref) \
	uint32_t UNUSED(pref##ruid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##euid) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setreuid(ctx, pref) \
	uint32_t &UNUSED(pref##ruid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##euid) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_setreuid(ctx, pref) \
	const uint32_t &UNUSED(pref##ruid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##euid) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_setregid ['gid_t rgid', 'gid_t egid']
#define locals_LINUX__ARM_sys_setregid(ctx, pref) \
	uint32_t UNUSED(pref##rgid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##egid) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setregid(ctx, pref) \
	uint32_t &UNUSED(pref##rgid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##egid) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_setregid(ctx, pref) \
	const uint32_t &UNUSED(pref##rgid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##egid) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_getgroups ['int gidsetsize', 'gid_t __user *grouplist']
#define locals_LINUX__ARM_sys_getgroups(ctx, pref) \
	int32_t UNUSED(pref##gidsetsize) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##grouplist) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_getgroups(ctx, pref) \
	int32_t &UNUSED(pref##gidsetsize) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##grouplist) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_getgroups(ctx, pref) \
	const int32_t &UNUSED(pref##gidsetsize) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##grouplist) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_setgroups ['int gidsetsize', 'gid_t __user *grouplist']
#define locals_LINUX__ARM_sys_setgroups(ctx, pref) \
	int32_t UNUSED(pref##gidsetsize) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##grouplist) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setgroups(ctx, pref) \
	int32_t &UNUSED(pref##gidsetsize) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##grouplist) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_setgroups(ctx, pref) \
	const int32_t &UNUSED(pref##gidsetsize) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##grouplist) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_fchown ['unsigned int fd', 'uid_t user', 'gid_t group']
#define locals_LINUX__ARM_sys_fchown(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##user) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##group) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_fchown(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##user) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##group) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_fchown(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##user) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##group) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_setresuid ['uid_t ruid', 'uid_t euid', 'uid_t suid']
#define locals_LINUX__ARM_sys_setresuid(ctx, pref) \
	uint32_t UNUSED(pref##ruid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##euid) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##suid) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setresuid(ctx, pref) \
	uint32_t &UNUSED(pref##ruid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##euid) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##suid) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_setresuid(ctx, pref) \
	const uint32_t &UNUSED(pref##ruid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##euid) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##suid) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_getresuid ['uid_t __user *ruid', 'uid_t __user *euid', 'uid_t __user *suid']
#define locals_LINUX__ARM_sys_getresuid(ctx, pref) \
	uint32_t UNUSED(pref##ruid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##euid) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##suid) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_getresuid(ctx, pref) \
	uint32_t &UNUSED(pref##ruid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##euid) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##suid) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_getresuid(ctx, pref) \
	const uint32_t &UNUSED(pref##ruid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##euid) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##suid) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_setresgid ['gid_t rgid', 'gid_t egid', 'gid_t sgid']
#define locals_LINUX__ARM_sys_setresgid(ctx, pref) \
	uint32_t UNUSED(pref##rgid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##egid) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##sgid) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setresgid(ctx, pref) \
	uint32_t &UNUSED(pref##rgid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##egid) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##sgid) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_setresgid(ctx, pref) \
	const uint32_t &UNUSED(pref##rgid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##egid) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##sgid) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_getresgid ['gid_t __user *rgid', 'gid_t __user *egid', 'gid_t __user *sgid']
#define locals_LINUX__ARM_sys_getresgid(ctx, pref) \
	uint32_t UNUSED(pref##rgid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##egid) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##sgid) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_getresgid(ctx, pref) \
	uint32_t &UNUSED(pref##rgid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##egid) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##sgid) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_getresgid(ctx, pref) \
	const uint32_t &UNUSED(pref##rgid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##egid) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##sgid) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_chown ['const char __user *filename', 'uid_t user', 'gid_t group']
#define locals_LINUX__ARM_sys_chown(ctx, pref) \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##user) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##group) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_chown(ctx, pref) \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##user) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##group) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_chown(ctx, pref) \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##user) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##group) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_setuid ['uid_t uid']
#define locals_LINUX__ARM_sys_setuid(ctx, pref) \
	uint32_t UNUSED(pref##uid) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setuid(ctx, pref) \
	uint32_t &UNUSED(pref##uid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_setuid(ctx, pref) \
	const uint32_t &UNUSED(pref##uid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_setgid ['gid_t gid']
#define locals_LINUX__ARM_sys_setgid(ctx, pref) \
	uint32_t UNUSED(pref##gid) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setgid(ctx, pref) \
	uint32_t &UNUSED(pref##gid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_setgid(ctx, pref) \
	const uint32_t &UNUSED(pref##gid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_setfsuid ['uid_t uid']
#define locals_LINUX__ARM_sys_setfsuid(ctx, pref) \
	uint32_t UNUSED(pref##uid) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setfsuid(ctx, pref) \
	uint32_t &UNUSED(pref##uid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_setfsuid(ctx, pref) \
	const uint32_t &UNUSED(pref##uid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_setfsgid ['gid_t gid']
#define locals_LINUX__ARM_sys_setfsgid(ctx, pref) \
	uint32_t UNUSED(pref##gid) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setfsgid(ctx, pref) \
	uint32_t &UNUSED(pref##gid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_setfsgid(ctx, pref) \
	const uint32_t &UNUSED(pref##gid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_getdents64 ['unsigned int fd', 'struct linux_dirent64 __user *dirent', 'unsigned int count']
#define locals_LINUX__ARM_sys_getdents64(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##dirent) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##count) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_getdents64(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##dirent) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##count) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_getdents64(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##dirent) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##count) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_pivot_root ['const char __user *new_root', 'const char __user *put_old']
#define locals_LINUX__ARM_sys_pivot_root(ctx, pref) \
	uint32_t UNUSED(pref##new_root) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##put_old) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_pivot_root(ctx, pref) \
	uint32_t &UNUSED(pref##new_root) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##put_old) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_pivot_root(ctx, pref) \
	const uint32_t &UNUSED(pref##new_root) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##put_old) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_mincore ['unsigned long start', 'size_t len', 'unsigned char __user *vec']
#define locals_LINUX__ARM_sys_mincore(ctx, pref) \
	uint32_t UNUSED(pref##start) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##len) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##vec) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_mincore(ctx, pref) \
	uint32_t &UNUSED(pref##start) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##len) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##vec) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_mincore(ctx, pref) \
	const uint32_t &UNUSED(pref##start) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##len) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##vec) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_madvise ['unsigned long start', 'size_t len', 'int behavior']
#define locals_LINUX__ARM_sys_madvise(ctx, pref) \
	uint32_t UNUSED(pref##start) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##len) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##behavior) = *(int32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_madvise(ctx, pref) \
	uint32_t &UNUSED(pref##start) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##len) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##behavior) = *reinterpret_cast<int32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_madvise(ctx, pref) \
	const uint32_t &UNUSED(pref##start) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##len) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##behavior) = *reinterpret_cast<const int32_t *>((ctx)->args[2]);
#endif

// long sys_fcntl64 ['unsigned int fd', 'unsigned int cmd', 'unsigned long arg']
#define locals_LINUX__ARM_sys_fcntl64(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##cmd) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##arg) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_fcntl64(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##cmd) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##arg) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_fcntl64(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##cmd) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##arg) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_gettid ['void']
#undef locals_LINUX__ARM_sys_gettid
#if defined(__cplusplus)
#undef references_LINUX__ARM_sys_gettid
#endif

// long sys_readahead ['int fd', 'loff_t offset', 'size_t count']
#define locals_LINUX__ARM_sys_readahead(ctx, pref) \
	int32_t UNUSED(pref##fd) = *(int32_t *)((ctx)->args[0]); \
	uint64_t UNUSED(pref##offset) = *(uint64_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##count) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_readahead(ctx, pref) \
	int32_t &UNUSED(pref##fd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint64_t &UNUSED(pref##offset) = *reinterpret_cast<uint64_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##count) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_readahead(ctx, pref) \
	const int32_t &UNUSED(pref##fd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint64_t &UNUSED(pref##offset) = *reinterpret_cast<const uint64_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##count) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_setxattr ['const char __user *path', 'const char __user *name', 'const void __user *value', 'size_t size', 'int flags']
#define locals_LINUX__ARM_sys_setxattr(ctx, pref) \
	uint32_t UNUSED(pref##path) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##name) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##value) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##size) = *(uint32_t *)((ctx)->args[3]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setxattr(ctx, pref) \
	uint32_t &UNUSED(pref##path) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##name) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##value) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##size) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_setxattr(ctx, pref) \
	const uint32_t &UNUSED(pref##path) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##name) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##value) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##size) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[4]);
#endif

// long sys_lsetxattr ['const char __user *path', 'const char __user *name', 'const void __user *value', 'size_t size', 'int flags']
#define locals_LINUX__ARM_sys_lsetxattr(ctx, pref) \
	uint32_t UNUSED(pref##path) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##name) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##value) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##size) = *(uint32_t *)((ctx)->args[3]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_lsetxattr(ctx, pref) \
	uint32_t &UNUSED(pref##path) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##name) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##value) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##size) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_lsetxattr(ctx, pref) \
	const uint32_t &UNUSED(pref##path) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##name) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##value) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##size) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[4]);
#endif

// long sys_fsetxattr ['int fd', 'const char __user *name', 'const void __user *value', 'size_t size', 'int flags']
#define locals_LINUX__ARM_sys_fsetxattr(ctx, pref) \
	int32_t UNUSED(pref##fd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##name) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##value) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##size) = *(uint32_t *)((ctx)->args[3]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_fsetxattr(ctx, pref) \
	int32_t &UNUSED(pref##fd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##name) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##value) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##size) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_fsetxattr(ctx, pref) \
	const int32_t &UNUSED(pref##fd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##name) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##value) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##size) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[4]);
#endif

// long sys_getxattr ['const char __user *path', 'const char __user *name', 'void __user *value', 'size_t size']
#define locals_LINUX__ARM_sys_getxattr(ctx, pref) \
	uint32_t UNUSED(pref##path) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##name) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##value) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##size) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_getxattr(ctx, pref) \
	uint32_t &UNUSED(pref##path) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##name) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##value) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##size) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_getxattr(ctx, pref) \
	const uint32_t &UNUSED(pref##path) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##name) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##value) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##size) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_lgetxattr ['const char __user *path', 'const char __user *name', 'void __user *value', 'size_t size']
#define locals_LINUX__ARM_sys_lgetxattr(ctx, pref) \
	uint32_t UNUSED(pref##path) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##name) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##value) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##size) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_lgetxattr(ctx, pref) \
	uint32_t &UNUSED(pref##path) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##name) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##value) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##size) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_lgetxattr(ctx, pref) \
	const uint32_t &UNUSED(pref##path) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##name) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##value) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##size) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_fgetxattr ['int fd', 'const char __user *name', 'void __user *value', 'size_t size']
#define locals_LINUX__ARM_sys_fgetxattr(ctx, pref) \
	int32_t UNUSED(pref##fd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##name) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##value) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##size) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_fgetxattr(ctx, pref) \
	int32_t &UNUSED(pref##fd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##name) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##value) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##size) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_fgetxattr(ctx, pref) \
	const int32_t &UNUSED(pref##fd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##name) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##value) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##size) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_listxattr ['const char __user *path', 'char __user *list', 'size_t size']
#define locals_LINUX__ARM_sys_listxattr(ctx, pref) \
	uint32_t UNUSED(pref##path) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##list) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##size) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_listxattr(ctx, pref) \
	uint32_t &UNUSED(pref##path) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##list) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##size) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_listxattr(ctx, pref) \
	const uint32_t &UNUSED(pref##path) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##list) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##size) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_llistxattr ['const char __user *path', 'char __user *list', 'size_t size']
#define locals_LINUX__ARM_sys_llistxattr(ctx, pref) \
	uint32_t UNUSED(pref##path) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##list) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##size) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_llistxattr(ctx, pref) \
	uint32_t &UNUSED(pref##path) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##list) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##size) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_llistxattr(ctx, pref) \
	const uint32_t &UNUSED(pref##path) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##list) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##size) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_flistxattr ['int fd', 'char __user *list', 'size_t size']
#define locals_LINUX__ARM_sys_flistxattr(ctx, pref) \
	int32_t UNUSED(pref##fd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##list) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##size) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_flistxattr(ctx, pref) \
	int32_t &UNUSED(pref##fd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##list) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##size) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_flistxattr(ctx, pref) \
	const int32_t &UNUSED(pref##fd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##list) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##size) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_removexattr ['const char __user *path', 'const char __user *name']
#define locals_LINUX__ARM_sys_removexattr(ctx, pref) \
	uint32_t UNUSED(pref##path) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##name) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_removexattr(ctx, pref) \
	uint32_t &UNUSED(pref##path) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##name) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_removexattr(ctx, pref) \
	const uint32_t &UNUSED(pref##path) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##name) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_lremovexattr ['const char __user *path', 'const char __user *name']
#define locals_LINUX__ARM_sys_lremovexattr(ctx, pref) \
	uint32_t UNUSED(pref##path) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##name) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_lremovexattr(ctx, pref) \
	uint32_t &UNUSED(pref##path) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##name) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_lremovexattr(ctx, pref) \
	const uint32_t &UNUSED(pref##path) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##name) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_fremovexattr ['int fd', 'const char __user *name']
#define locals_LINUX__ARM_sys_fremovexattr(ctx, pref) \
	int32_t UNUSED(pref##fd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##name) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_fremovexattr(ctx, pref) \
	int32_t &UNUSED(pref##fd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##name) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_fremovexattr(ctx, pref) \
	const int32_t &UNUSED(pref##fd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##name) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_tkill ['pid_t pid', 'int sig']
#define locals_LINUX__ARM_sys_tkill(ctx, pref) \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##sig) = *(int32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_tkill(ctx, pref) \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##sig) = *reinterpret_cast<int32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_tkill(ctx, pref) \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##sig) = *reinterpret_cast<const int32_t *>((ctx)->args[1]);
#endif

// long sys_sendfile64 ['int out_fd', 'int in_fd', 'loff_t __user *offset', 'size_t count']
#define locals_LINUX__ARM_sys_sendfile64(ctx, pref) \
	int32_t UNUSED(pref##out_fd) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##in_fd) = *(int32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##offset) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##count) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sendfile64(ctx, pref) \
	int32_t &UNUSED(pref##out_fd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##in_fd) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##offset) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##count) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_sendfile64(ctx, pref) \
	const int32_t &UNUSED(pref##out_fd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##in_fd) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##offset) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##count) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_futex ['u32 __user *uaddr', 'int op', 'u32 val', 'struct timespec __user *utime', 'u32 __user *uaddr2', 'u32 val3']
#define locals_LINUX__ARM_sys_futex(ctx, pref) \
	uint32_t UNUSED(pref##uaddr) = *(uint32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##op) = *(int32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##val) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##utime) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##uaddr2) = *(uint32_t *)((ctx)->args[4]); \
	uint32_t UNUSED(pref##val3) = *(uint32_t *)((ctx)->args[5]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_futex(ctx, pref) \
	uint32_t &UNUSED(pref##uaddr) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##op) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##val) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##utime) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##uaddr2) = *reinterpret_cast<uint32_t *>((ctx)->args[4]); \
	uint32_t &UNUSED(pref##val3) = *reinterpret_cast<uint32_t *>((ctx)->args[5]);
#define creferences_LINUX__ARM_sys_futex(ctx, pref) \
	const uint32_t &UNUSED(pref##uaddr) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##op) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##val) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##utime) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##uaddr2) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]); \
	const uint32_t &UNUSED(pref##val3) = *reinterpret_cast<const uint32_t *>((ctx)->args[5]);
#endif

// long sys_sched_setaffinity ['pid_t pid', 'unsigned int len', 'unsigned long __user *user_mask_ptr']
#define locals_LINUX__ARM_sys_sched_setaffinity(ctx, pref) \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##len) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##user_mask_ptr) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sched_setaffinity(ctx, pref) \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##len) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##user_mask_ptr) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_sched_setaffinity(ctx, pref) \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##len) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##user_mask_ptr) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_sched_getaffinity ['pid_t pid', 'unsigned int len', 'unsigned long __user *user_mask_ptr']
#define locals_LINUX__ARM_sys_sched_getaffinity(ctx, pref) \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##len) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##user_mask_ptr) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sched_getaffinity(ctx, pref) \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##len) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##user_mask_ptr) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_sched_getaffinity(ctx, pref) \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##len) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##user_mask_ptr) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_io_setup ['unsigned nr_reqs', 'aio_context_t __user *ctx']
#define locals_LINUX__ARM_sys_io_setup(ctx, pref) \
	uint32_t UNUSED(pref##nr_reqs) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##ctx) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_io_setup(ctx, pref) \
	uint32_t &UNUSED(pref##nr_reqs) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##ctx) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_io_setup(ctx, pref) \
	const uint32_t &UNUSED(pref##nr_reqs) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##ctx) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_io_destroy ['aio_context_t ctx']
#define locals_LINUX__ARM_sys_io_destroy(ctx, pref) \
	uint32_t UNUSED(pref##ctx) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_io_destroy(ctx, pref) \
	uint32_t &UNUSED(pref##ctx) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_io_destroy(ctx, pref) \
	const uint32_t &UNUSED(pref##ctx) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_io_getevents ['aio_context_t ctx_id', 'long min_nr', 'long nr', 'struct io_event __user *events', 'struct timespec __user *timeout']
#define locals_LINUX__ARM_sys_io_getevents(ctx, pref) \
	uint32_t UNUSED(pref##ctx_id) = *(uint32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##min_nr) = *(int32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##nr) = *(int32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##events) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##timeout) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_io_getevents(ctx, pref) \
	uint32_t &UNUSED(pref##ctx_id) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##min_nr) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##nr) = *reinterpret_cast<int32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##events) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##timeout) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_io_getevents(ctx, pref) \
	const uint32_t &UNUSED(pref##ctx_id) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##min_nr) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##nr) = *reinterpret_cast<const int32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##events) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##timeout) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_io_submit ['aio_context_t', 'long', 'struct iocb __user * __user *']
#define locals_LINUX__ARM_sys_io_submit(ctx, pref) \
	uint32_t UNUSED(pref##arg0) = *(uint32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##arg1) = *(int32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##arg2) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_io_submit(ctx, pref) \
	uint32_t &UNUSED(pref##arg0) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##arg1) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_io_submit(ctx, pref) \
	const uint32_t &UNUSED(pref##arg0) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##arg1) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_io_cancel ['aio_context_t ctx_id', 'struct iocb __user *iocb', 'struct io_event __user *result']
#define locals_LINUX__ARM_sys_io_cancel(ctx, pref) \
	uint32_t UNUSED(pref##ctx_id) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##iocb) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##result) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_io_cancel(ctx, pref) \
	uint32_t &UNUSED(pref##ctx_id) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##iocb) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##result) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_io_cancel(ctx, pref) \
	const uint32_t &UNUSED(pref##ctx_id) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##iocb) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##result) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_exit_group ['int error_code']
#define locals_LINUX__ARM_sys_exit_group(ctx, pref) \
	int32_t UNUSED(pref##error_code) = *(int32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_exit_group(ctx, pref) \
	int32_t &UNUSED(pref##error_code) = *reinterpret_cast<int32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_exit_group(ctx, pref) \
	const int32_t &UNUSED(pref##error_code) = *reinterpret_cast<const int32_t *>((ctx)->args[0]);
#endif

// long sys_lookup_dcookie ['u64 cookie64', 'char __user *buf', 'size_t len']
#define locals_LINUX__ARM_sys_lookup_dcookie(ctx, pref) \
	uint64_t UNUSED(pref##cookie64) = *(uint64_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##buf) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##len) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_lookup_dcookie(ctx, pref) \
	uint64_t &UNUSED(pref##cookie64) = *reinterpret_cast<uint64_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##buf) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##len) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_lookup_dcookie(ctx, pref) \
	const uint64_t &UNUSED(pref##cookie64) = *reinterpret_cast<const uint64_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##buf) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##len) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_epoll_create ['int size']
#define locals_LINUX__ARM_sys_epoll_create(ctx, pref) \
	int32_t UNUSED(pref##size) = *(int32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_epoll_create(ctx, pref) \
	int32_t &UNUSED(pref##size) = *reinterpret_cast<int32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_epoll_create(ctx, pref) \
	const int32_t &UNUSED(pref##size) = *reinterpret_cast<const int32_t *>((ctx)->args[0]);
#endif

// long sys_epoll_ctl ['int epfd', 'int op', 'int fd', 'struct epoll_event __user *event']
#define locals_LINUX__ARM_sys_epoll_ctl(ctx, pref) \
	int32_t UNUSED(pref##epfd) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##op) = *(int32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##fd) = *(int32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##event) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_epoll_ctl(ctx, pref) \
	int32_t &UNUSED(pref##epfd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##op) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##fd) = *reinterpret_cast<int32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##event) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_epoll_ctl(ctx, pref) \
	const int32_t &UNUSED(pref##epfd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##op) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##fd) = *reinterpret_cast<const int32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##event) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_epoll_wait ['int epfd', 'struct epoll_event __user *events', 'int maxevents', 'int timeout']
#define locals_LINUX__ARM_sys_epoll_wait(ctx, pref) \
	int32_t UNUSED(pref##epfd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##events) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##maxevents) = *(int32_t *)((ctx)->args[2]); \
	int32_t UNUSED(pref##timeout) = *(int32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_epoll_wait(ctx, pref) \
	int32_t &UNUSED(pref##epfd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##events) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##maxevents) = *reinterpret_cast<int32_t *>((ctx)->args[2]); \
	int32_t &UNUSED(pref##timeout) = *reinterpret_cast<int32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_epoll_wait(ctx, pref) \
	const int32_t &UNUSED(pref##epfd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##events) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##maxevents) = *reinterpret_cast<const int32_t *>((ctx)->args[2]); \
	const int32_t &UNUSED(pref##timeout) = *reinterpret_cast<const int32_t *>((ctx)->args[3]);
#endif

// long sys_remap_file_pages ['unsigned long start', 'unsigned long size', 'unsigned long prot', 'unsigned long pgoff', 'unsigned long flags']
#define locals_LINUX__ARM_sys_remap_file_pages(ctx, pref) \
	uint32_t UNUSED(pref##start) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##size) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##prot) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##pgoff) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_remap_file_pages(ctx, pref) \
	uint32_t &UNUSED(pref##start) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##size) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##prot) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##pgoff) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_remap_file_pages(ctx, pref) \
	const uint32_t &UNUSED(pref##start) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##size) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##prot) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##pgoff) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_set_tid_address ['int __user *tidptr']
#define locals_LINUX__ARM_sys_set_tid_address(ctx, pref) \
	uint32_t UNUSED(pref##tidptr) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_set_tid_address(ctx, pref) \
	uint32_t &UNUSED(pref##tidptr) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_set_tid_address(ctx, pref) \
	const uint32_t &UNUSED(pref##tidptr) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_timer_create ['clockid_t which_clock', 'struct sigevent __user *timer_event_spec', 'timer_t __user *created_timer_id']
#define locals_LINUX__ARM_sys_timer_create(ctx, pref) \
	uint32_t UNUSED(pref##which_clock) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##timer_event_spec) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##created_timer_id) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_timer_create(ctx, pref) \
	uint32_t &UNUSED(pref##which_clock) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##timer_event_spec) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##created_timer_id) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_timer_create(ctx, pref) \
	const uint32_t &UNUSED(pref##which_clock) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##timer_event_spec) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##created_timer_id) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_timer_settime ['timer_t timer_id', 'int flags', 'const struct itimerspec __user *new_setting', 'struct itimerspec __user *old_setting']
#define locals_LINUX__ARM_sys_timer_settime(ctx, pref) \
	uint32_t UNUSED(pref##timer_id) = *(uint32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##new_setting) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##old_setting) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_timer_settime(ctx, pref) \
	uint32_t &UNUSED(pref##timer_id) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##new_setting) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##old_setting) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_timer_settime(ctx, pref) \
	const uint32_t &UNUSED(pref##timer_id) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##new_setting) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##old_setting) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_timer_gettime ['timer_t timer_id', 'struct itimerspec __user *setting']
#define locals_LINUX__ARM_sys_timer_gettime(ctx, pref) \
	uint32_t UNUSED(pref##timer_id) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##setting) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_timer_gettime(ctx, pref) \
	uint32_t &UNUSED(pref##timer_id) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##setting) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_timer_gettime(ctx, pref) \
	const uint32_t &UNUSED(pref##timer_id) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##setting) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_timer_getoverrun ['timer_t timer_id']
#define locals_LINUX__ARM_sys_timer_getoverrun(ctx, pref) \
	uint32_t UNUSED(pref##timer_id) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_timer_getoverrun(ctx, pref) \
	uint32_t &UNUSED(pref##timer_id) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_timer_getoverrun(ctx, pref) \
	const uint32_t &UNUSED(pref##timer_id) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_timer_delete ['timer_t timer_id']
#define locals_LINUX__ARM_sys_timer_delete(ctx, pref) \
	uint32_t UNUSED(pref##timer_id) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_timer_delete(ctx, pref) \
	uint32_t &UNUSED(pref##timer_id) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_timer_delete(ctx, pref) \
	const uint32_t &UNUSED(pref##timer_id) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_clock_settime ['clockid_t which_clock', 'const struct timespec __user *tp']
#define locals_LINUX__ARM_sys_clock_settime(ctx, pref) \
	uint32_t UNUSED(pref##which_clock) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##tp) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_clock_settime(ctx, pref) \
	uint32_t &UNUSED(pref##which_clock) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##tp) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_clock_settime(ctx, pref) \
	const uint32_t &UNUSED(pref##which_clock) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##tp) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_clock_gettime ['clockid_t which_clock', 'struct timespec __user *tp']
#define locals_LINUX__ARM_sys_clock_gettime(ctx, pref) \
	uint32_t UNUSED(pref##which_clock) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##tp) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_clock_gettime(ctx, pref) \
	uint32_t &UNUSED(pref##which_clock) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##tp) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_clock_gettime(ctx, pref) \
	const uint32_t &UNUSED(pref##which_clock) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##tp) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_clock_getres ['clockid_t which_clock', 'struct timespec __user *tp']
#define locals_LINUX__ARM_sys_clock_getres(ctx, pref) \
	uint32_t UNUSED(pref##which_clock) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##tp) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_clock_getres(ctx, pref) \
	uint32_t &UNUSED(pref##which_clock) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##tp) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_clock_getres(ctx, pref) \
	const uint32_t &UNUSED(pref##which_clock) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##tp) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_clock_nanosleep ['clockid_t which_clock', 'int flags', 'const struct timespec __user *rqtp', 'struct timespec __user *rmtp']
#define locals_LINUX__ARM_sys_clock_nanosleep(ctx, pref) \
	uint32_t UNUSED(pref##which_clock) = *(uint32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##rqtp) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##rmtp) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_clock_nanosleep(ctx, pref) \
	uint32_t &UNUSED(pref##which_clock) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##rqtp) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##rmtp) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_clock_nanosleep(ctx, pref) \
	const uint32_t &UNUSED(pref##which_clock) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##rqtp) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##rmtp) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_statfs64 ['const char __user *path', 'size_t sz', 'struct statfs64 __user *buf']
#define locals_LINUX__ARM_sys_statfs64(ctx, pref) \
	uint32_t UNUSED(pref##path) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##sz) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##buf) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_statfs64(ctx, pref) \
	uint32_t &UNUSED(pref##path) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##sz) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##buf) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_statfs64(ctx, pref) \
	const uint32_t &UNUSED(pref##path) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##sz) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##buf) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_fstatfs64 ['unsigned int fd', 'size_t sz', 'struct statfs64 __user *buf']
#define locals_LINUX__ARM_sys_fstatfs64(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##sz) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##buf) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_fstatfs64(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##sz) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##buf) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_fstatfs64(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##sz) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##buf) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_tgkill ['pid_t tgid', 'pid_t pid', 'int sig']
#define locals_LINUX__ARM_sys_tgkill(ctx, pref) \
	uint32_t UNUSED(pref##tgid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##sig) = *(int32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_tgkill(ctx, pref) \
	uint32_t &UNUSED(pref##tgid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##sig) = *reinterpret_cast<int32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_tgkill(ctx, pref) \
	const uint32_t &UNUSED(pref##tgid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##sig) = *reinterpret_cast<const int32_t *>((ctx)->args[2]);
#endif

// long sys_utimes ['char __user *filename', 'struct timeval __user *utimes']
#define locals_LINUX__ARM_sys_utimes(ctx, pref) \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##utimes) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_utimes(ctx, pref) \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##utimes) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_utimes(ctx, pref) \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##utimes) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_arm_fadvise64_64 ['int fd', 'int advice', 'loff_t offset', 'loff_t len']
#define locals_LINUX__ARM_sys_arm_fadvise64_64(ctx, pref) \
	int32_t UNUSED(pref##fd) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##advice) = *(int32_t *)((ctx)->args[1]); \
	uint64_t UNUSED(pref##offset) = *(uint64_t *)((ctx)->args[2]); \
	uint64_t UNUSED(pref##len) = *(uint64_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_arm_fadvise64_64(ctx, pref) \
	int32_t &UNUSED(pref##fd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##advice) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	uint64_t &UNUSED(pref##offset) = *reinterpret_cast<uint64_t *>((ctx)->args[2]); \
	uint64_t &UNUSED(pref##len) = *reinterpret_cast<uint64_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_arm_fadvise64_64(ctx, pref) \
	const int32_t &UNUSED(pref##fd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##advice) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const uint64_t &UNUSED(pref##offset) = *reinterpret_cast<const uint64_t *>((ctx)->args[2]); \
	const uint64_t &UNUSED(pref##len) = *reinterpret_cast<const uint64_t *>((ctx)->args[3]);
#endif

// long sys_pciconfig_iobase ['long which', 'unsigned long bus', 'unsigned long devfn']
#define locals_LINUX__ARM_sys_pciconfig_iobase(ctx, pref) \
	int32_t UNUSED(pref##which) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##bus) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##devfn) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_pciconfig_iobase(ctx, pref) \
	int32_t &UNUSED(pref##which) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##bus) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##devfn) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_pciconfig_iobase(ctx, pref) \
	const int32_t &UNUSED(pref##which) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##bus) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##devfn) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_pciconfig_read ['unsigned long bus', 'unsigned long dfn', 'unsigned long off', 'unsigned long len', 'void __user *buf']
#define locals_LINUX__ARM_sys_pciconfig_read(ctx, pref) \
	uint32_t UNUSED(pref##bus) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##dfn) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##off) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##len) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##buf) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_pciconfig_read(ctx, pref) \
	uint32_t &UNUSED(pref##bus) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##dfn) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##off) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##len) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##buf) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_pciconfig_read(ctx, pref) \
	const uint32_t &UNUSED(pref##bus) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##dfn) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##off) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##len) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##buf) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_pciconfig_write ['unsigned long bus', 'unsigned long dfn', 'unsigned long off', 'unsigned long len', 'void __user *buf']
#define locals_LINUX__ARM_sys_pciconfig_write(ctx, pref) \
	uint32_t UNUSED(pref##bus) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##dfn) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##off) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##len) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##buf) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_pciconfig_write(ctx, pref) \
	uint32_t &UNUSED(pref##bus) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##dfn) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##off) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##len) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##buf) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_pciconfig_write(ctx, pref) \
	const uint32_t &UNUSED(pref##bus) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##dfn) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##off) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##len) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##buf) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_mq_open ['const char __user *name', 'int oflag', 'umode_t mode', 'struct mq_attr __user *attr']
#define locals_LINUX__ARM_sys_mq_open(ctx, pref) \
	uint32_t UNUSED(pref##name) = *(uint32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##oflag) = *(int32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##mode) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##attr) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_mq_open(ctx, pref) \
	uint32_t &UNUSED(pref##name) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##oflag) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##mode) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##attr) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_mq_open(ctx, pref) \
	const uint32_t &UNUSED(pref##name) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##oflag) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##mode) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##attr) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_mq_unlink ['const char __user *name']
#define locals_LINUX__ARM_sys_mq_unlink(ctx, pref) \
	uint32_t UNUSED(pref##name) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_mq_unlink(ctx, pref) \
	uint32_t &UNUSED(pref##name) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_mq_unlink(ctx, pref) \
	const uint32_t &UNUSED(pref##name) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_mq_timedsend ['mqd_t mqdes', 'const char __user *msg_ptr', 'size_t msg_len', 'unsigned int msg_prio', 'const struct timespec __user *abs_timeout']
#define locals_LINUX__ARM_sys_mq_timedsend(ctx, pref) \
	uint32_t UNUSED(pref##mqdes) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##msg_ptr) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##msg_len) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##msg_prio) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##abs_timeout) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_mq_timedsend(ctx, pref) \
	uint32_t &UNUSED(pref##mqdes) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##msg_ptr) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##msg_len) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##msg_prio) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##abs_timeout) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_mq_timedsend(ctx, pref) \
	const uint32_t &UNUSED(pref##mqdes) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##msg_ptr) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##msg_len) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##msg_prio) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##abs_timeout) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_mq_timedreceive ['mqd_t mqdes', 'char __user *msg_ptr', 'size_t msg_len', 'unsigned int __user *msg_prio', 'const struct timespec __user *abs_timeout']
#define locals_LINUX__ARM_sys_mq_timedreceive(ctx, pref) \
	uint32_t UNUSED(pref##mqdes) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##msg_ptr) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##msg_len) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##msg_prio) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##abs_timeout) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_mq_timedreceive(ctx, pref) \
	uint32_t &UNUSED(pref##mqdes) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##msg_ptr) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##msg_len) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##msg_prio) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##abs_timeout) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_mq_timedreceive(ctx, pref) \
	const uint32_t &UNUSED(pref##mqdes) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##msg_ptr) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##msg_len) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##msg_prio) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##abs_timeout) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_mq_notify ['mqd_t mqdes', 'const struct sigevent __user *notification']
#define locals_LINUX__ARM_sys_mq_notify(ctx, pref) \
	uint32_t UNUSED(pref##mqdes) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##notification) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_mq_notify(ctx, pref) \
	uint32_t &UNUSED(pref##mqdes) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##notification) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_mq_notify(ctx, pref) \
	const uint32_t &UNUSED(pref##mqdes) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##notification) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_mq_getsetattr ['mqd_t mqdes', 'const struct mq_attr __user *mqstat', 'struct mq_attr __user *omqstat']
#define locals_LINUX__ARM_sys_mq_getsetattr(ctx, pref) \
	uint32_t UNUSED(pref##mqdes) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##mqstat) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##omqstat) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_mq_getsetattr(ctx, pref) \
	uint32_t &UNUSED(pref##mqdes) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##mqstat) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##omqstat) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_mq_getsetattr(ctx, pref) \
	const uint32_t &UNUSED(pref##mqdes) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##mqstat) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##omqstat) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_waitid ['int which', 'pid_t pid', 'struct siginfo __user *infop', 'int options', 'struct rusage __user *ru']
#define locals_LINUX__ARM_sys_waitid(ctx, pref) \
	int32_t UNUSED(pref##which) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##infop) = *(uint32_t *)((ctx)->args[2]); \
	int32_t UNUSED(pref##options) = *(int32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##ru) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_waitid(ctx, pref) \
	int32_t &UNUSED(pref##which) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##infop) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	int32_t &UNUSED(pref##options) = *reinterpret_cast<int32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##ru) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_waitid(ctx, pref) \
	const int32_t &UNUSED(pref##which) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##infop) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const int32_t &UNUSED(pref##options) = *reinterpret_cast<const int32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##ru) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_socket ['int', 'int', 'int']
#define locals_LINUX__ARM_sys_socket(ctx, pref) \
	int32_t UNUSED(pref##arg0) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##arg1) = *(int32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##arg2) = *(int32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_socket(ctx, pref) \
	int32_t &UNUSED(pref##arg0) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##arg1) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##arg2) = *reinterpret_cast<int32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_socket(ctx, pref) \
	const int32_t &UNUSED(pref##arg0) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##arg1) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##arg2) = *reinterpret_cast<const int32_t *>((ctx)->args[2]);
#endif

// long sys_bind ['int', 'struct sockaddr __user *', 'int']
#define locals_LINUX__ARM_sys_bind(ctx, pref) \
	int32_t UNUSED(pref##arg0) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##arg1) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##arg2) = *(int32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_bind(ctx, pref) \
	int32_t &UNUSED(pref##arg0) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##arg2) = *reinterpret_cast<int32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_bind(ctx, pref) \
	const int32_t &UNUSED(pref##arg0) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##arg2) = *reinterpret_cast<const int32_t *>((ctx)->args[2]);
#endif

// long sys_connect ['int', 'struct sockaddr __user *', 'int']
#define locals_LINUX__ARM_sys_connect(ctx, pref) \
	int32_t UNUSED(pref##arg0) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##arg1) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##arg2) = *(int32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_connect(ctx, pref) \
	int32_t &UNUSED(pref##arg0) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##arg2) = *reinterpret_cast<int32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_connect(ctx, pref) \
	const int32_t &UNUSED(pref##arg0) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##arg2) = *reinterpret_cast<const int32_t *>((ctx)->args[2]);
#endif

// long sys_listen ['int', 'int']
#define locals_LINUX__ARM_sys_listen(ctx, pref) \
	int32_t UNUSED(pref##arg0) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##arg1) = *(int32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_listen(ctx, pref) \
	int32_t &UNUSED(pref##arg0) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##arg1) = *reinterpret_cast<int32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_listen(ctx, pref) \
	const int32_t &UNUSED(pref##arg0) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##arg1) = *reinterpret_cast<const int32_t *>((ctx)->args[1]);
#endif

// long sys_accept ['int', 'struct sockaddr __user *', 'int __user *']
#define locals_LINUX__ARM_sys_accept(ctx, pref) \
	int32_t UNUSED(pref##arg0) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##arg1) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##arg2) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_accept(ctx, pref) \
	int32_t &UNUSED(pref##arg0) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_accept(ctx, pref) \
	const int32_t &UNUSED(pref##arg0) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_getsockname ['int', 'struct sockaddr __user *', 'int __user *']
#define locals_LINUX__ARM_sys_getsockname(ctx, pref) \
	int32_t UNUSED(pref##arg0) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##arg1) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##arg2) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_getsockname(ctx, pref) \
	int32_t &UNUSED(pref##arg0) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_getsockname(ctx, pref) \
	const int32_t &UNUSED(pref##arg0) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_getpeername ['int', 'struct sockaddr __user *', 'int __user *']
#define locals_LINUX__ARM_sys_getpeername(ctx, pref) \
	int32_t UNUSED(pref##arg0) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##arg1) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##arg2) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_getpeername(ctx, pref) \
	int32_t &UNUSED(pref##arg0) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_getpeername(ctx, pref) \
	const int32_t &UNUSED(pref##arg0) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_socketpair ['int', 'int', 'int', 'int __user *']
#define locals_LINUX__ARM_sys_socketpair(ctx, pref) \
	int32_t UNUSED(pref##arg0) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##arg1) = *(int32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##arg2) = *(int32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##arg3) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_socketpair(ctx, pref) \
	int32_t &UNUSED(pref##arg0) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##arg1) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##arg2) = *reinterpret_cast<int32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##arg3) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_socketpair(ctx, pref) \
	const int32_t &UNUSED(pref##arg0) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##arg1) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##arg2) = *reinterpret_cast<const int32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##arg3) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_send ['int', 'void __user *', 'size_t', 'unsigned']
#define locals_LINUX__ARM_sys_send(ctx, pref) \
	int32_t UNUSED(pref##arg0) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##arg1) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##arg2) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##arg3) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_send(ctx, pref) \
	int32_t &UNUSED(pref##arg0) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##arg3) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_send(ctx, pref) \
	const int32_t &UNUSED(pref##arg0) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##arg3) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_sendto ['int', 'void __user *', 'size_t', 'unsigned', 'struct sockaddr __user *', 'int']
#define locals_LINUX__ARM_sys_sendto(ctx, pref) \
	int32_t UNUSED(pref##arg0) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##arg1) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##arg2) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##arg3) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##arg4) = *(uint32_t *)((ctx)->args[4]); \
	int32_t UNUSED(pref##arg5) = *(int32_t *)((ctx)->args[5]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sendto(ctx, pref) \
	int32_t &UNUSED(pref##arg0) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##arg3) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##arg4) = *reinterpret_cast<uint32_t *>((ctx)->args[4]); \
	int32_t &UNUSED(pref##arg5) = *reinterpret_cast<int32_t *>((ctx)->args[5]);
#define creferences_LINUX__ARM_sys_sendto(ctx, pref) \
	const int32_t &UNUSED(pref##arg0) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##arg3) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##arg4) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]); \
	const int32_t &UNUSED(pref##arg5) = *reinterpret_cast<const int32_t *>((ctx)->args[5]);
#endif

// long sys_recv ['int', 'void __user *', 'size_t', 'unsigned']
#define locals_LINUX__ARM_sys_recv(ctx, pref) \
	int32_t UNUSED(pref##arg0) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##arg1) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##arg2) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##arg3) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_recv(ctx, pref) \
	int32_t &UNUSED(pref##arg0) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##arg3) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_recv(ctx, pref) \
	const int32_t &UNUSED(pref##arg0) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##arg3) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_recvfrom ['int', 'void __user *', 'size_t', 'unsigned', 'struct sockaddr __user *', 'int __user *']
#define locals_LINUX__ARM_sys_recvfrom(ctx, pref) \
	int32_t UNUSED(pref##arg0) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##arg1) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##arg2) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##arg3) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##arg4) = *(uint32_t *)((ctx)->args[4]); \
	uint32_t UNUSED(pref##arg5) = *(uint32_t *)((ctx)->args[5]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_recvfrom(ctx, pref) \
	int32_t &UNUSED(pref##arg0) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##arg3) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##arg4) = *reinterpret_cast<uint32_t *>((ctx)->args[4]); \
	uint32_t &UNUSED(pref##arg5) = *reinterpret_cast<uint32_t *>((ctx)->args[5]);
#define creferences_LINUX__ARM_sys_recvfrom(ctx, pref) \
	const int32_t &UNUSED(pref##arg0) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##arg3) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##arg4) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]); \
	const uint32_t &UNUSED(pref##arg5) = *reinterpret_cast<const uint32_t *>((ctx)->args[5]);
#endif

// long sys_shutdown ['int', 'int']
#define locals_LINUX__ARM_sys_shutdown(ctx, pref) \
	int32_t UNUSED(pref##arg0) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##arg1) = *(int32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_shutdown(ctx, pref) \
	int32_t &UNUSED(pref##arg0) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##arg1) = *reinterpret_cast<int32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_shutdown(ctx, pref) \
	const int32_t &UNUSED(pref##arg0) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##arg1) = *reinterpret_cast<const int32_t *>((ctx)->args[1]);
#endif

// long sys_setsockopt ['int fd', 'int level', 'int optname', 'char __user *optval', 'int optlen']
#define locals_LINUX__ARM_sys_setsockopt(ctx, pref) \
	int32_t UNUSED(pref##fd) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##level) = *(int32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##optname) = *(int32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##optval) = *(uint32_t *)((ctx)->args[3]); \
	int32_t UNUSED(pref##optlen) = *(int32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setsockopt(ctx, pref) \
	int32_t &UNUSED(pref##fd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##level) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##optname) = *reinterpret_cast<int32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##optval) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	int32_t &UNUSED(pref##optlen) = *reinterpret_cast<int32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_setsockopt(ctx, pref) \
	const int32_t &UNUSED(pref##fd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##level) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##optname) = *reinterpret_cast<const int32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##optval) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const int32_t &UNUSED(pref##optlen) = *reinterpret_cast<const int32_t *>((ctx)->args[4]);
#endif

// long sys_getsockopt ['int fd', 'int level', 'int optname', 'char __user *optval', 'int __user *optlen']
#define locals_LINUX__ARM_sys_getsockopt(ctx, pref) \
	int32_t UNUSED(pref##fd) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##level) = *(int32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##optname) = *(int32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##optval) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##optlen) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_getsockopt(ctx, pref) \
	int32_t &UNUSED(pref##fd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##level) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##optname) = *reinterpret_cast<int32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##optval) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##optlen) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_getsockopt(ctx, pref) \
	const int32_t &UNUSED(pref##fd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##level) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##optname) = *reinterpret_cast<const int32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##optval) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##optlen) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_sendmsg ['int fd', 'struct user_msghdr __user *msg', 'unsigned flags']
#define locals_LINUX__ARM_sys_sendmsg(ctx, pref) \
	int32_t UNUSED(pref##fd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##msg) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sendmsg(ctx, pref) \
	int32_t &UNUSED(pref##fd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##msg) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_sendmsg(ctx, pref) \
	const int32_t &UNUSED(pref##fd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##msg) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_recvmsg ['int fd', 'struct user_msghdr __user *msg', 'unsigned flags']
#define locals_LINUX__ARM_sys_recvmsg(ctx, pref) \
	int32_t UNUSED(pref##fd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##msg) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_recvmsg(ctx, pref) \
	int32_t &UNUSED(pref##fd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##msg) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_recvmsg(ctx, pref) \
	const int32_t &UNUSED(pref##fd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##msg) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_semop ['int semid', 'struct sembuf __user *sops', 'unsigned nsops']
#define locals_LINUX__ARM_sys_semop(ctx, pref) \
	int32_t UNUSED(pref##semid) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##sops) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##nsops) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_semop(ctx, pref) \
	int32_t &UNUSED(pref##semid) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##sops) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##nsops) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_semop(ctx, pref) \
	const int32_t &UNUSED(pref##semid) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##sops) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##nsops) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_semget ['key_t key', 'int nsems', 'int semflg']
#define locals_LINUX__ARM_sys_semget(ctx, pref) \
	uint32_t UNUSED(pref##key) = *(uint32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##nsems) = *(int32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##semflg) = *(int32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_semget(ctx, pref) \
	uint32_t &UNUSED(pref##key) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##nsems) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##semflg) = *reinterpret_cast<int32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_semget(ctx, pref) \
	const uint32_t &UNUSED(pref##key) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##nsems) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##semflg) = *reinterpret_cast<const int32_t *>((ctx)->args[2]);
#endif

// long sys_semctl ['int semid', 'int semnum', 'int cmd', 'unsigned long arg']
#define locals_LINUX__ARM_sys_semctl(ctx, pref) \
	int32_t UNUSED(pref##semid) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##semnum) = *(int32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##cmd) = *(int32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##arg) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_semctl(ctx, pref) \
	int32_t &UNUSED(pref##semid) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##semnum) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##cmd) = *reinterpret_cast<int32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##arg) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_semctl(ctx, pref) \
	const int32_t &UNUSED(pref##semid) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##semnum) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##cmd) = *reinterpret_cast<const int32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##arg) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_msgsnd ['int msqid', 'struct msgbuf __user *msgp', 'size_t msgsz', 'int msgflg']
#define locals_LINUX__ARM_sys_msgsnd(ctx, pref) \
	int32_t UNUSED(pref##msqid) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##msgp) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##msgsz) = *(uint32_t *)((ctx)->args[2]); \
	int32_t UNUSED(pref##msgflg) = *(int32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_msgsnd(ctx, pref) \
	int32_t &UNUSED(pref##msqid) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##msgp) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##msgsz) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	int32_t &UNUSED(pref##msgflg) = *reinterpret_cast<int32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_msgsnd(ctx, pref) \
	const int32_t &UNUSED(pref##msqid) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##msgp) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##msgsz) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const int32_t &UNUSED(pref##msgflg) = *reinterpret_cast<const int32_t *>((ctx)->args[3]);
#endif

// long sys_msgrcv ['int msqid', 'struct msgbuf __user *msgp', 'size_t msgsz', 'long msgtyp', 'int msgflg']
#define locals_LINUX__ARM_sys_msgrcv(ctx, pref) \
	int32_t UNUSED(pref##msqid) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##msgp) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##msgsz) = *(uint32_t *)((ctx)->args[2]); \
	int32_t UNUSED(pref##msgtyp) = *(int32_t *)((ctx)->args[3]); \
	int32_t UNUSED(pref##msgflg) = *(int32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_msgrcv(ctx, pref) \
	int32_t &UNUSED(pref##msqid) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##msgp) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##msgsz) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	int32_t &UNUSED(pref##msgtyp) = *reinterpret_cast<int32_t *>((ctx)->args[3]); \
	int32_t &UNUSED(pref##msgflg) = *reinterpret_cast<int32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_msgrcv(ctx, pref) \
	const int32_t &UNUSED(pref##msqid) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##msgp) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##msgsz) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const int32_t &UNUSED(pref##msgtyp) = *reinterpret_cast<const int32_t *>((ctx)->args[3]); \
	const int32_t &UNUSED(pref##msgflg) = *reinterpret_cast<const int32_t *>((ctx)->args[4]);
#endif

// long sys_msgget ['key_t key', 'int msgflg']
#define locals_LINUX__ARM_sys_msgget(ctx, pref) \
	uint32_t UNUSED(pref##key) = *(uint32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##msgflg) = *(int32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_msgget(ctx, pref) \
	uint32_t &UNUSED(pref##key) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##msgflg) = *reinterpret_cast<int32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_msgget(ctx, pref) \
	const uint32_t &UNUSED(pref##key) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##msgflg) = *reinterpret_cast<const int32_t *>((ctx)->args[1]);
#endif

// long sys_msgctl ['int msqid', 'int cmd', 'struct msqid_ds __user *buf']
#define locals_LINUX__ARM_sys_msgctl(ctx, pref) \
	int32_t UNUSED(pref##msqid) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##cmd) = *(int32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##buf) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_msgctl(ctx, pref) \
	int32_t &UNUSED(pref##msqid) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##cmd) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##buf) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_msgctl(ctx, pref) \
	const int32_t &UNUSED(pref##msqid) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##cmd) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##buf) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_shmat ['int shmid', 'char __user *shmaddr', 'int shmflg']
#define locals_LINUX__ARM_sys_shmat(ctx, pref) \
	int32_t UNUSED(pref##shmid) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##shmaddr) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##shmflg) = *(int32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_shmat(ctx, pref) \
	int32_t &UNUSED(pref##shmid) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##shmaddr) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##shmflg) = *reinterpret_cast<int32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_shmat(ctx, pref) \
	const int32_t &UNUSED(pref##shmid) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##shmaddr) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##shmflg) = *reinterpret_cast<const int32_t *>((ctx)->args[2]);
#endif

// long sys_shmdt ['char __user *shmaddr']
#define locals_LINUX__ARM_sys_shmdt(ctx, pref) \
	uint32_t UNUSED(pref##shmaddr) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_shmdt(ctx, pref) \
	uint32_t &UNUSED(pref##shmaddr) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_shmdt(ctx, pref) \
	const uint32_t &UNUSED(pref##shmaddr) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_shmget ['key_t key', 'size_t size', 'int flag']
#define locals_LINUX__ARM_sys_shmget(ctx, pref) \
	uint32_t UNUSED(pref##key) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##size) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##flag) = *(int32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_shmget(ctx, pref) \
	uint32_t &UNUSED(pref##key) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##size) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##flag) = *reinterpret_cast<int32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_shmget(ctx, pref) \
	const uint32_t &UNUSED(pref##key) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##size) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##flag) = *reinterpret_cast<const int32_t *>((ctx)->args[2]);
#endif

// long sys_shmctl ['int shmid', 'int cmd', 'struct shmid_ds __user *buf']
#define locals_LINUX__ARM_sys_shmctl(ctx, pref) \
	int32_t UNUSED(pref##shmid) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##cmd) = *(int32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##buf) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_shmctl(ctx, pref) \
	int32_t &UNUSED(pref##shmid) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##cmd) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##buf) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_shmctl(ctx, pref) \
	const int32_t &UNUSED(pref##shmid) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##cmd) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##buf) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_add_key ['const char __user *_type', 'const char __user *_description', 'const void __user *_payload', 'size_t plen', 'key_serial_t destringid']
#define locals_LINUX__ARM_sys_add_key(ctx, pref) \
	uint32_t UNUSED(pref##_type) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##_description) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##_payload) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##plen) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##destringid) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_add_key(ctx, pref) \
	uint32_t &UNUSED(pref##_type) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##_description) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##_payload) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##plen) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##destringid) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_add_key(ctx, pref) \
	const uint32_t &UNUSED(pref##_type) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##_description) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##_payload) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##plen) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##destringid) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_request_key ['const char __user *_type', 'const char __user *_description', 'const char __user *_callout_info', 'key_serial_t destringid']
#define locals_LINUX__ARM_sys_request_key(ctx, pref) \
	uint32_t UNUSED(pref##_type) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##_description) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##_callout_info) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##destringid) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_request_key(ctx, pref) \
	uint32_t &UNUSED(pref##_type) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##_description) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##_callout_info) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##destringid) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_request_key(ctx, pref) \
	const uint32_t &UNUSED(pref##_type) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##_description) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##_callout_info) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##destringid) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_keyctl ['int cmd', 'unsigned long arg2', 'unsigned long arg3', 'unsigned long arg4', 'unsigned long arg5']
#define locals_LINUX__ARM_sys_keyctl(ctx, pref) \
	int32_t UNUSED(pref##cmd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##arg2) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##arg3) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##arg4) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##arg5) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_keyctl(ctx, pref) \
	int32_t &UNUSED(pref##cmd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##arg3) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##arg4) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##arg5) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_keyctl(ctx, pref) \
	const int32_t &UNUSED(pref##cmd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##arg3) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##arg4) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##arg5) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_semtimedop ['int semid', 'struct sembuf __user *sops', 'unsigned nsops', 'const struct timespec __user *timeout']
#define locals_LINUX__ARM_sys_semtimedop(ctx, pref) \
	int32_t UNUSED(pref##semid) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##sops) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##nsops) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##timeout) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_semtimedop(ctx, pref) \
	int32_t &UNUSED(pref##semid) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##sops) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##nsops) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##timeout) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_semtimedop(ctx, pref) \
	const int32_t &UNUSED(pref##semid) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##sops) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##nsops) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##timeout) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_ioprio_set ['int which', 'int who', 'int ioprio']
#define locals_LINUX__ARM_sys_ioprio_set(ctx, pref) \
	int32_t UNUSED(pref##which) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##who) = *(int32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##ioprio) = *(int32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_ioprio_set(ctx, pref) \
	int32_t &UNUSED(pref##which) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##who) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##ioprio) = *reinterpret_cast<int32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_ioprio_set(ctx, pref) \
	const int32_t &UNUSED(pref##which) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##who) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##ioprio) = *reinterpret_cast<const int32_t *>((ctx)->args[2]);
#endif

// long sys_ioprio_get ['int which', 'int who']
#define locals_LINUX__ARM_sys_ioprio_get(ctx, pref) \
	int32_t UNUSED(pref##which) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##who) = *(int32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_ioprio_get(ctx, pref) \
	int32_t &UNUSED(pref##which) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##who) = *reinterpret_cast<int32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_ioprio_get(ctx, pref) \
	const int32_t &UNUSED(pref##which) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##who) = *reinterpret_cast<const int32_t *>((ctx)->args[1]);
#endif

// long sys_inotify_init ['void']
#undef locals_LINUX__ARM_sys_inotify_init
#if defined(__cplusplus)
#undef references_LINUX__ARM_sys_inotify_init
#endif

// long sys_inotify_add_watch ['int fd', 'const char __user *path', 'u32 mask']
#define locals_LINUX__ARM_sys_inotify_add_watch(ctx, pref) \
	int32_t UNUSED(pref##fd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##path) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##mask) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_inotify_add_watch(ctx, pref) \
	int32_t &UNUSED(pref##fd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##path) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##mask) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_inotify_add_watch(ctx, pref) \
	const int32_t &UNUSED(pref##fd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##path) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##mask) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_inotify_rm_watch ['int fd', '__s32 wd']
#define locals_LINUX__ARM_sys_inotify_rm_watch(ctx, pref) \
	int32_t UNUSED(pref##fd) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##wd) = *(int32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_inotify_rm_watch(ctx, pref) \
	int32_t &UNUSED(pref##fd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##wd) = *reinterpret_cast<int32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_inotify_rm_watch(ctx, pref) \
	const int32_t &UNUSED(pref##fd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##wd) = *reinterpret_cast<const int32_t *>((ctx)->args[1]);
#endif

// long sys_mbind ['unsigned long start', 'unsigned long len', 'unsigned long mode', 'const unsigned long __user *nmask', 'unsigned long maxnode', 'unsigned flags']
#define locals_LINUX__ARM_sys_mbind(ctx, pref) \
	uint32_t UNUSED(pref##start) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##len) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##mode) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##nmask) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##maxnode) = *(uint32_t *)((ctx)->args[4]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[5]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_mbind(ctx, pref) \
	uint32_t &UNUSED(pref##start) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##len) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##mode) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##nmask) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##maxnode) = *reinterpret_cast<uint32_t *>((ctx)->args[4]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[5]);
#define creferences_LINUX__ARM_sys_mbind(ctx, pref) \
	const uint32_t &UNUSED(pref##start) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##len) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##mode) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##nmask) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##maxnode) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[5]);
#endif

// long sys_get_mempolicy ['int __user *policy', 'unsigned long __user *nmask', 'unsigned long maxnode', 'unsigned long addr', 'unsigned long flags']
#define locals_LINUX__ARM_sys_get_mempolicy(ctx, pref) \
	uint32_t UNUSED(pref##policy) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##nmask) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##maxnode) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##addr) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_get_mempolicy(ctx, pref) \
	uint32_t &UNUSED(pref##policy) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##nmask) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##maxnode) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##addr) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_get_mempolicy(ctx, pref) \
	const uint32_t &UNUSED(pref##policy) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##nmask) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##maxnode) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##addr) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_set_mempolicy ['int mode', 'const unsigned long __user *nmask', 'unsigned long maxnode']
#define locals_LINUX__ARM_sys_set_mempolicy(ctx, pref) \
	int32_t UNUSED(pref##mode) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##nmask) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##maxnode) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_set_mempolicy(ctx, pref) \
	int32_t &UNUSED(pref##mode) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##nmask) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##maxnode) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_set_mempolicy(ctx, pref) \
	const int32_t &UNUSED(pref##mode) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##nmask) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##maxnode) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_openat ['int dfd', 'const char __user *filename', 'int flags', 'umode_t mode']
#define locals_LINUX__ARM_sys_openat(ctx, pref) \
	int32_t UNUSED(pref##dfd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##mode) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_openat(ctx, pref) \
	int32_t &UNUSED(pref##dfd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##mode) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_openat(ctx, pref) \
	const int32_t &UNUSED(pref##dfd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##mode) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_mkdirat ['int dfd', 'const char __user *pathname', 'umode_t mode']
#define locals_LINUX__ARM_sys_mkdirat(ctx, pref) \
	int32_t UNUSED(pref##dfd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##pathname) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##mode) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_mkdirat(ctx, pref) \
	int32_t &UNUSED(pref##dfd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##pathname) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##mode) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_mkdirat(ctx, pref) \
	const int32_t &UNUSED(pref##dfd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##pathname) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##mode) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_mknodat ['int dfd', 'const char __user *filename', 'umode_t mode', 'unsigned dev']
#define locals_LINUX__ARM_sys_mknodat(ctx, pref) \
	int32_t UNUSED(pref##dfd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##mode) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##dev) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_mknodat(ctx, pref) \
	int32_t &UNUSED(pref##dfd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##mode) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##dev) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_mknodat(ctx, pref) \
	const int32_t &UNUSED(pref##dfd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##mode) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##dev) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_fchownat ['int dfd', 'const char __user *filename', 'uid_t user', 'gid_t group', 'int flag']
#define locals_LINUX__ARM_sys_fchownat(ctx, pref) \
	int32_t UNUSED(pref##dfd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##user) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##group) = *(uint32_t *)((ctx)->args[3]); \
	int32_t UNUSED(pref##flag) = *(int32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_fchownat(ctx, pref) \
	int32_t &UNUSED(pref##dfd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##user) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##group) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	int32_t &UNUSED(pref##flag) = *reinterpret_cast<int32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_fchownat(ctx, pref) \
	const int32_t &UNUSED(pref##dfd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##user) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##group) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const int32_t &UNUSED(pref##flag) = *reinterpret_cast<const int32_t *>((ctx)->args[4]);
#endif

// long sys_futimesat ['int dfd', 'const char __user *filename', 'struct timeval __user *utimes']
#define locals_LINUX__ARM_sys_futimesat(ctx, pref) \
	int32_t UNUSED(pref##dfd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##utimes) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_futimesat(ctx, pref) \
	int32_t &UNUSED(pref##dfd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##utimes) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_futimesat(ctx, pref) \
	const int32_t &UNUSED(pref##dfd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##utimes) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_fstatat64 ['int dfd', 'const char __user *filename', 'struct stat64 __user *statbuf', 'int flag']
#define locals_LINUX__ARM_sys_fstatat64(ctx, pref) \
	int32_t UNUSED(pref##dfd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##statbuf) = *(uint32_t *)((ctx)->args[2]); \
	int32_t UNUSED(pref##flag) = *(int32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_fstatat64(ctx, pref) \
	int32_t &UNUSED(pref##dfd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##statbuf) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	int32_t &UNUSED(pref##flag) = *reinterpret_cast<int32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_fstatat64(ctx, pref) \
	const int32_t &UNUSED(pref##dfd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##statbuf) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const int32_t &UNUSED(pref##flag) = *reinterpret_cast<const int32_t *>((ctx)->args[3]);
#endif

// long sys_unlinkat ['int dfd', 'const char __user *pathname', 'int flag']
#define locals_LINUX__ARM_sys_unlinkat(ctx, pref) \
	int32_t UNUSED(pref##dfd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##pathname) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##flag) = *(int32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_unlinkat(ctx, pref) \
	int32_t &UNUSED(pref##dfd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##pathname) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##flag) = *reinterpret_cast<int32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_unlinkat(ctx, pref) \
	const int32_t &UNUSED(pref##dfd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##pathname) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##flag) = *reinterpret_cast<const int32_t *>((ctx)->args[2]);
#endif

// long sys_renameat ['int olddfd', 'const char __user *oldname', 'int newdfd', 'const char __user *newname']
#define locals_LINUX__ARM_sys_renameat(ctx, pref) \
	int32_t UNUSED(pref##olddfd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##oldname) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##newdfd) = *(int32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##newname) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_renameat(ctx, pref) \
	int32_t &UNUSED(pref##olddfd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##oldname) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##newdfd) = *reinterpret_cast<int32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##newname) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_renameat(ctx, pref) \
	const int32_t &UNUSED(pref##olddfd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##oldname) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##newdfd) = *reinterpret_cast<const int32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##newname) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_linkat ['int olddfd', 'const char __user *oldname', 'int newdfd', 'const char __user *newname', 'int flags']
#define locals_LINUX__ARM_sys_linkat(ctx, pref) \
	int32_t UNUSED(pref##olddfd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##oldname) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##newdfd) = *(int32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##newname) = *(uint32_t *)((ctx)->args[3]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_linkat(ctx, pref) \
	int32_t &UNUSED(pref##olddfd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##oldname) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##newdfd) = *reinterpret_cast<int32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##newname) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_linkat(ctx, pref) \
	const int32_t &UNUSED(pref##olddfd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##oldname) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##newdfd) = *reinterpret_cast<const int32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##newname) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[4]);
#endif

// long sys_symlinkat ['const char __user *oldname', 'int newdfd', 'const char __user *newname']
#define locals_LINUX__ARM_sys_symlinkat(ctx, pref) \
	uint32_t UNUSED(pref##oldname) = *(uint32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##newdfd) = *(int32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##newname) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_symlinkat(ctx, pref) \
	uint32_t &UNUSED(pref##oldname) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##newdfd) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##newname) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_symlinkat(ctx, pref) \
	const uint32_t &UNUSED(pref##oldname) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##newdfd) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##newname) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_readlinkat ['int dfd', 'const char __user *path', 'char __user *buf', 'int bufsiz']
#define locals_LINUX__ARM_sys_readlinkat(ctx, pref) \
	int32_t UNUSED(pref##dfd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##path) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##buf) = *(uint32_t *)((ctx)->args[2]); \
	int32_t UNUSED(pref##bufsiz) = *(int32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_readlinkat(ctx, pref) \
	int32_t &UNUSED(pref##dfd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##path) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##buf) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	int32_t &UNUSED(pref##bufsiz) = *reinterpret_cast<int32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_readlinkat(ctx, pref) \
	const int32_t &UNUSED(pref##dfd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##path) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##buf) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const int32_t &UNUSED(pref##bufsiz) = *reinterpret_cast<const int32_t *>((ctx)->args[3]);
#endif

// long sys_fchmodat ['int dfd', 'const char __user *filename', 'umode_t mode']
#define locals_LINUX__ARM_sys_fchmodat(ctx, pref) \
	int32_t UNUSED(pref##dfd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##mode) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_fchmodat(ctx, pref) \
	int32_t &UNUSED(pref##dfd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##mode) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_fchmodat(ctx, pref) \
	const int32_t &UNUSED(pref##dfd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##mode) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_faccessat ['int dfd', 'const char __user *filename', 'int mode']
#define locals_LINUX__ARM_sys_faccessat(ctx, pref) \
	int32_t UNUSED(pref##dfd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##mode) = *(int32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_faccessat(ctx, pref) \
	int32_t &UNUSED(pref##dfd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##mode) = *reinterpret_cast<int32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_faccessat(ctx, pref) \
	const int32_t &UNUSED(pref##dfd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##mode) = *reinterpret_cast<const int32_t *>((ctx)->args[2]);
#endif

// long sys_pselect6 ['int', 'fd_set __user *', 'fd_set __user *', 'fd_set __user *', 'struct timespec __user *', 'void __user *']
#define locals_LINUX__ARM_sys_pselect6(ctx, pref) \
	int32_t UNUSED(pref##arg0) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##arg1) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##arg2) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##arg3) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##arg4) = *(uint32_t *)((ctx)->args[4]); \
	uint32_t UNUSED(pref##arg5) = *(uint32_t *)((ctx)->args[5]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_pselect6(ctx, pref) \
	int32_t &UNUSED(pref##arg0) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##arg3) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##arg4) = *reinterpret_cast<uint32_t *>((ctx)->args[4]); \
	uint32_t &UNUSED(pref##arg5) = *reinterpret_cast<uint32_t *>((ctx)->args[5]);
#define creferences_LINUX__ARM_sys_pselect6(ctx, pref) \
	const int32_t &UNUSED(pref##arg0) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##arg3) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##arg4) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]); \
	const uint32_t &UNUSED(pref##arg5) = *reinterpret_cast<const uint32_t *>((ctx)->args[5]);
#endif

// long sys_ppoll ['struct pollfd __user *', 'unsigned int', 'struct timespec __user *', 'const sigset_t __user *', 'size_t']
#define locals_LINUX__ARM_sys_ppoll(ctx, pref) \
	uint32_t UNUSED(pref##arg0) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##arg1) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##arg2) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##arg3) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##arg4) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_ppoll(ctx, pref) \
	uint32_t &UNUSED(pref##arg0) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##arg3) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##arg4) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_ppoll(ctx, pref) \
	const uint32_t &UNUSED(pref##arg0) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##arg3) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##arg4) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_unshare ['unsigned long unshare_flags']
#define locals_LINUX__ARM_sys_unshare(ctx, pref) \
	uint32_t UNUSED(pref##unshare_flags) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_unshare(ctx, pref) \
	uint32_t &UNUSED(pref##unshare_flags) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_unshare(ctx, pref) \
	const uint32_t &UNUSED(pref##unshare_flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_set_robust_list ['struct robust_list_head __user *head', 'size_t len']
#define locals_LINUX__ARM_sys_set_robust_list(ctx, pref) \
	uint32_t UNUSED(pref##head) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##len) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_set_robust_list(ctx, pref) \
	uint32_t &UNUSED(pref##head) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##len) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_set_robust_list(ctx, pref) \
	const uint32_t &UNUSED(pref##head) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##len) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_get_robust_list ['int pid', 'struct robust_list_head __user * __user *head_ptr', 'size_t __user *len_ptr']
#define locals_LINUX__ARM_sys_get_robust_list(ctx, pref) \
	int32_t UNUSED(pref##pid) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##head_ptr) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##len_ptr) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_get_robust_list(ctx, pref) \
	int32_t &UNUSED(pref##pid) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##head_ptr) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##len_ptr) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_get_robust_list(ctx, pref) \
	const int32_t &UNUSED(pref##pid) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##head_ptr) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##len_ptr) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_splice ['int fd_in', 'loff_t __user *off_in', 'int fd_out', 'loff_t __user *off_out', 'size_t len', 'unsigned int flags']
#define locals_LINUX__ARM_sys_splice(ctx, pref) \
	int32_t UNUSED(pref##fd_in) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##off_in) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##fd_out) = *(int32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##off_out) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##len) = *(uint32_t *)((ctx)->args[4]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[5]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_splice(ctx, pref) \
	int32_t &UNUSED(pref##fd_in) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##off_in) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##fd_out) = *reinterpret_cast<int32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##off_out) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##len) = *reinterpret_cast<uint32_t *>((ctx)->args[4]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[5]);
#define creferences_LINUX__ARM_sys_splice(ctx, pref) \
	const int32_t &UNUSED(pref##fd_in) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##off_in) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##fd_out) = *reinterpret_cast<const int32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##off_out) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##len) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[5]);
#endif

// long sys_sync_file_range2 ['int fd', 'unsigned int flags', 'loff_t offset', 'loff_t nbytes']
#define locals_LINUX__ARM_sys_sync_file_range2(ctx, pref) \
	int32_t UNUSED(pref##fd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[1]); \
	uint64_t UNUSED(pref##offset) = *(uint64_t *)((ctx)->args[2]); \
	uint64_t UNUSED(pref##nbytes) = *(uint64_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sync_file_range2(ctx, pref) \
	int32_t &UNUSED(pref##fd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint64_t &UNUSED(pref##offset) = *reinterpret_cast<uint64_t *>((ctx)->args[2]); \
	uint64_t &UNUSED(pref##nbytes) = *reinterpret_cast<uint64_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_sync_file_range2(ctx, pref) \
	const int32_t &UNUSED(pref##fd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint64_t &UNUSED(pref##offset) = *reinterpret_cast<const uint64_t *>((ctx)->args[2]); \
	const uint64_t &UNUSED(pref##nbytes) = *reinterpret_cast<const uint64_t *>((ctx)->args[3]);
#endif

// long sys_tee ['int fdin', 'int fdout', 'size_t len', 'unsigned int flags']
#define locals_LINUX__ARM_sys_tee(ctx, pref) \
	int32_t UNUSED(pref##fdin) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##fdout) = *(int32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##len) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_tee(ctx, pref) \
	int32_t &UNUSED(pref##fdin) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##fdout) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##len) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_tee(ctx, pref) \
	const int32_t &UNUSED(pref##fdin) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##fdout) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##len) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_vmsplice ['int fd', 'const struct iovec __user *iov', 'unsigned long nr_segs', 'unsigned int flags']
#define locals_LINUX__ARM_sys_vmsplice(ctx, pref) \
	int32_t UNUSED(pref##fd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##iov) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##nr_segs) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_vmsplice(ctx, pref) \
	int32_t &UNUSED(pref##fd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##iov) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##nr_segs) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_vmsplice(ctx, pref) \
	const int32_t &UNUSED(pref##fd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##iov) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##nr_segs) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_move_pages ['pid_t pid', 'unsigned long nr_pages', 'const void __user * __user *pages', 'const int __user *nodes', 'int __user *status', 'int flags']
#define locals_LINUX__ARM_sys_move_pages(ctx, pref) \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##nr_pages) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##pages) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##nodes) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##status) = *(uint32_t *)((ctx)->args[4]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[5]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_move_pages(ctx, pref) \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##nr_pages) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##pages) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##nodes) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##status) = *reinterpret_cast<uint32_t *>((ctx)->args[4]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[5]);
#define creferences_LINUX__ARM_sys_move_pages(ctx, pref) \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##nr_pages) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##pages) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##nodes) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##status) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[5]);
#endif

// long sys_getcpu ['unsigned __user *cpu', 'unsigned __user *node', 'struct getcpu_cache __user *cache']
#define locals_LINUX__ARM_sys_getcpu(ctx, pref) \
	uint32_t UNUSED(pref##_cpu) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##node) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##cache) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_getcpu(ctx, pref) \
	uint32_t &UNUSED(pref##_cpu) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##node) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##cache) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_getcpu(ctx, pref) \
	const uint32_t &UNUSED(pref##_cpu) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##node) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##cache) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_epoll_pwait ['int epfd', 'struct epoll_event __user *events', 'int maxevents', 'int timeout', 'const sigset_t __user *sigmask', 'size_t sigsetsize']
#define locals_LINUX__ARM_sys_epoll_pwait(ctx, pref) \
	int32_t UNUSED(pref##epfd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##events) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##maxevents) = *(int32_t *)((ctx)->args[2]); \
	int32_t UNUSED(pref##timeout) = *(int32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##sigmask) = *(uint32_t *)((ctx)->args[4]); \
	uint32_t UNUSED(pref##sigsetsize) = *(uint32_t *)((ctx)->args[5]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_epoll_pwait(ctx, pref) \
	int32_t &UNUSED(pref##epfd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##events) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##maxevents) = *reinterpret_cast<int32_t *>((ctx)->args[2]); \
	int32_t &UNUSED(pref##timeout) = *reinterpret_cast<int32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##sigmask) = *reinterpret_cast<uint32_t *>((ctx)->args[4]); \
	uint32_t &UNUSED(pref##sigsetsize) = *reinterpret_cast<uint32_t *>((ctx)->args[5]);
#define creferences_LINUX__ARM_sys_epoll_pwait(ctx, pref) \
	const int32_t &UNUSED(pref##epfd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##events) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##maxevents) = *reinterpret_cast<const int32_t *>((ctx)->args[2]); \
	const int32_t &UNUSED(pref##timeout) = *reinterpret_cast<const int32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##sigmask) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]); \
	const uint32_t &UNUSED(pref##sigsetsize) = *reinterpret_cast<const uint32_t *>((ctx)->args[5]);
#endif

// long sys_kexec_load ['unsigned long entry', 'unsigned long nr_segments', 'struct kexec_segment __user *segments', 'unsigned long flags']
#define locals_LINUX__ARM_sys_kexec_load(ctx, pref) \
	uint32_t UNUSED(pref##entry) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##nr_segments) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##segments) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_kexec_load(ctx, pref) \
	uint32_t &UNUSED(pref##entry) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##nr_segments) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##segments) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_kexec_load(ctx, pref) \
	const uint32_t &UNUSED(pref##entry) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##nr_segments) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##segments) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_utimensat ['int dfd', 'const char __user *filename', 'struct timespec __user *utimes', 'int flags']
#define locals_LINUX__ARM_sys_utimensat(ctx, pref) \
	int32_t UNUSED(pref##dfd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##utimes) = *(uint32_t *)((ctx)->args[2]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_utimensat(ctx, pref) \
	int32_t &UNUSED(pref##dfd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##utimes) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_utimensat(ctx, pref) \
	const int32_t &UNUSED(pref##dfd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##utimes) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[3]);
#endif

// long sys_signalfd ['int ufd', 'sigset_t __user *user_mask', 'size_t sizemask']
#define locals_LINUX__ARM_sys_signalfd(ctx, pref) \
	int32_t UNUSED(pref##ufd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##user_mask) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##sizemask) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_signalfd(ctx, pref) \
	int32_t &UNUSED(pref##ufd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##user_mask) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##sizemask) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_signalfd(ctx, pref) \
	const int32_t &UNUSED(pref##ufd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##user_mask) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##sizemask) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_timerfd_create ['int clockid', 'int flags']
#define locals_LINUX__ARM_sys_timerfd_create(ctx, pref) \
	int32_t UNUSED(pref##clockid) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_timerfd_create(ctx, pref) \
	int32_t &UNUSED(pref##clockid) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_timerfd_create(ctx, pref) \
	const int32_t &UNUSED(pref##clockid) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[1]);
#endif

// long sys_eventfd ['unsigned int count']
#define locals_LINUX__ARM_sys_eventfd(ctx, pref) \
	uint32_t UNUSED(pref##count) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_eventfd(ctx, pref) \
	uint32_t &UNUSED(pref##count) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_eventfd(ctx, pref) \
	const uint32_t &UNUSED(pref##count) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif

// long sys_fallocate ['int fd', 'int mode', 'loff_t offset', 'loff_t len']
#define locals_LINUX__ARM_sys_fallocate(ctx, pref) \
	int32_t UNUSED(pref##fd) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##mode) = *(int32_t *)((ctx)->args[1]); \
	uint64_t UNUSED(pref##offset) = *(uint64_t *)((ctx)->args[2]); \
	uint64_t UNUSED(pref##len) = *(uint64_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_fallocate(ctx, pref) \
	int32_t &UNUSED(pref##fd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##mode) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	uint64_t &UNUSED(pref##offset) = *reinterpret_cast<uint64_t *>((ctx)->args[2]); \
	uint64_t &UNUSED(pref##len) = *reinterpret_cast<uint64_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_fallocate(ctx, pref) \
	const int32_t &UNUSED(pref##fd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##mode) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const uint64_t &UNUSED(pref##offset) = *reinterpret_cast<const uint64_t *>((ctx)->args[2]); \
	const uint64_t &UNUSED(pref##len) = *reinterpret_cast<const uint64_t *>((ctx)->args[3]);
#endif

// long sys_timerfd_settime ['int ufd', 'int flags', 'const struct itimerspec __user *utmr', 'struct itimerspec __user *otmr']
#define locals_LINUX__ARM_sys_timerfd_settime(ctx, pref) \
	int32_t UNUSED(pref##ufd) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##utmr) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##otmr) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_timerfd_settime(ctx, pref) \
	int32_t &UNUSED(pref##ufd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##utmr) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##otmr) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_timerfd_settime(ctx, pref) \
	const int32_t &UNUSED(pref##ufd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##utmr) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##otmr) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_timerfd_gettime ['int ufd', 'struct itimerspec __user *otmr']
#define locals_LINUX__ARM_sys_timerfd_gettime(ctx, pref) \
	int32_t UNUSED(pref##ufd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##otmr) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_timerfd_gettime(ctx, pref) \
	int32_t &UNUSED(pref##ufd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##otmr) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_timerfd_gettime(ctx, pref) \
	const int32_t &UNUSED(pref##ufd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##otmr) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_signalfd4 ['int ufd', 'sigset_t __user *user_mask', 'size_t sizemask', 'int flags']
#define locals_LINUX__ARM_sys_signalfd4(ctx, pref) \
	int32_t UNUSED(pref##ufd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##user_mask) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##sizemask) = *(uint32_t *)((ctx)->args[2]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_signalfd4(ctx, pref) \
	int32_t &UNUSED(pref##ufd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##user_mask) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##sizemask) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_signalfd4(ctx, pref) \
	const int32_t &UNUSED(pref##ufd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##user_mask) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##sizemask) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[3]);
#endif

// long sys_eventfd2 ['unsigned int count', 'int flags']
#define locals_LINUX__ARM_sys_eventfd2(ctx, pref) \
	uint32_t UNUSED(pref##count) = *(uint32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_eventfd2(ctx, pref) \
	uint32_t &UNUSED(pref##count) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_eventfd2(ctx, pref) \
	const uint32_t &UNUSED(pref##count) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[1]);
#endif

// long sys_epoll_create1 ['int flags']
#define locals_LINUX__ARM_sys_epoll_create1(ctx, pref) \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_epoll_create1(ctx, pref) \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_epoll_create1(ctx, pref) \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[0]);
#endif

// long sys_dup3 ['unsigned int oldfd', 'unsigned int newfd', 'int flags']
#define locals_LINUX__ARM_sys_dup3(ctx, pref) \
	uint32_t UNUSED(pref##oldfd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##newfd) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_dup3(ctx, pref) \
	uint32_t &UNUSED(pref##oldfd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##newfd) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_dup3(ctx, pref) \
	const uint32_t &UNUSED(pref##oldfd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##newfd) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[2]);
#endif

// long sys_pipe2 ['int __user *fildes', 'int flags']
#define locals_LINUX__ARM_sys_pipe2(ctx, pref) \
	uint32_t UNUSED(pref##fildes) = *(uint32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_pipe2(ctx, pref) \
	uint32_t &UNUSED(pref##fildes) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_pipe2(ctx, pref) \
	const uint32_t &UNUSED(pref##fildes) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[1]);
#endif

// long sys_inotify_init1 ['int flags']
#define locals_LINUX__ARM_sys_inotify_init1(ctx, pref) \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_inotify_init1(ctx, pref) \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_inotify_init1(ctx, pref) \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[0]);
#endif

// long sys_preadv ['unsigned long fd', 'const struct iovec __user *vec', 'unsigned long vlen', 'unsigned long pos_l', 'unsigned long pos_h']
#define locals_LINUX__ARM_sys_preadv(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##vec) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##vlen) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##pos_l) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##pos_h) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_preadv(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##vec) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##vlen) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##pos_l) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##pos_h) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_preadv(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##vec) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##vlen) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##pos_l) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##pos_h) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_pwritev ['unsigned long fd', 'const struct iovec __user *vec', 'unsigned long vlen', 'unsigned long pos_l', 'unsigned long pos_h']
#define locals_LINUX__ARM_sys_pwritev(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##vec) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##vlen) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##pos_l) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##pos_h) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_pwritev(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##vec) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##vlen) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##pos_l) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##pos_h) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_pwritev(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##vec) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##vlen) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##pos_l) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##pos_h) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_rt_tgsigqueueinfo ['pid_t tgid', 'pid_t pid', 'int sig', 'siginfo_t __user *uinfo']
#define locals_LINUX__ARM_sys_rt_tgsigqueueinfo(ctx, pref) \
	uint32_t UNUSED(pref##tgid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##sig) = *(int32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##uinfo) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_rt_tgsigqueueinfo(ctx, pref) \
	uint32_t &UNUSED(pref##tgid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##sig) = *reinterpret_cast<int32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##uinfo) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_rt_tgsigqueueinfo(ctx, pref) \
	const uint32_t &UNUSED(pref##tgid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##sig) = *reinterpret_cast<const int32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##uinfo) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_perf_event_open ['struct perf_event_attr __user *attr_uptr', 'pid_t pid', 'int cpu', 'int group_fd', 'unsigned long flags']
#define locals_LINUX__ARM_sys_perf_event_open(ctx, pref) \
	uint32_t UNUSED(pref##attr_uptr) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##_cpu) = *(int32_t *)((ctx)->args[2]); \
	int32_t UNUSED(pref##group_fd) = *(int32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_perf_event_open(ctx, pref) \
	uint32_t &UNUSED(pref##attr_uptr) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##_cpu) = *reinterpret_cast<int32_t *>((ctx)->args[2]); \
	int32_t &UNUSED(pref##group_fd) = *reinterpret_cast<int32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_perf_event_open(ctx, pref) \
	const uint32_t &UNUSED(pref##attr_uptr) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##_cpu) = *reinterpret_cast<const int32_t *>((ctx)->args[2]); \
	const int32_t &UNUSED(pref##group_fd) = *reinterpret_cast<const int32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_recvmmsg ['int fd', 'struct mmsghdr __user *msg', 'unsigned int vlen', 'unsigned flags', 'struct timespec __user *timeout']
#define locals_LINUX__ARM_sys_recvmmsg(ctx, pref) \
	int32_t UNUSED(pref##fd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##msg) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##vlen) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##timeout) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_recvmmsg(ctx, pref) \
	int32_t &UNUSED(pref##fd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##msg) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##vlen) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##timeout) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_recvmmsg(ctx, pref) \
	const int32_t &UNUSED(pref##fd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##msg) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##vlen) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##timeout) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_accept4 ['int', 'struct sockaddr __user *', 'int __user *', 'int']
#define locals_LINUX__ARM_sys_accept4(ctx, pref) \
	int32_t UNUSED(pref##arg0) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##arg1) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##arg2) = *(uint32_t *)((ctx)->args[2]); \
	int32_t UNUSED(pref##arg3) = *(int32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_accept4(ctx, pref) \
	int32_t &UNUSED(pref##arg0) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	int32_t &UNUSED(pref##arg3) = *reinterpret_cast<int32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_accept4(ctx, pref) \
	const int32_t &UNUSED(pref##arg0) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##arg1) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##arg2) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const int32_t &UNUSED(pref##arg3) = *reinterpret_cast<const int32_t *>((ctx)->args[3]);
#endif

// long sys_fanotify_init ['unsigned int flags', 'unsigned int event_f_flags']
#define locals_LINUX__ARM_sys_fanotify_init(ctx, pref) \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##event_f_flags) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_fanotify_init(ctx, pref) \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##event_f_flags) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_fanotify_init(ctx, pref) \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##event_f_flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_fanotify_mark ['int fanotify_fd', 'unsigned int flags', 'u64 mask', 'int fd', 'const char __user *pathname']
#define locals_LINUX__ARM_sys_fanotify_mark(ctx, pref) \
	int32_t UNUSED(pref##fanotify_fd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[1]); \
	uint64_t UNUSED(pref##mask) = *(uint64_t *)((ctx)->args[2]); \
	int32_t UNUSED(pref##fd) = *(int32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##pathname) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_fanotify_mark(ctx, pref) \
	int32_t &UNUSED(pref##fanotify_fd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint64_t &UNUSED(pref##mask) = *reinterpret_cast<uint64_t *>((ctx)->args[2]); \
	int32_t &UNUSED(pref##fd) = *reinterpret_cast<int32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##pathname) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_fanotify_mark(ctx, pref) \
	const int32_t &UNUSED(pref##fanotify_fd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint64_t &UNUSED(pref##mask) = *reinterpret_cast<const uint64_t *>((ctx)->args[2]); \
	const int32_t &UNUSED(pref##fd) = *reinterpret_cast<const int32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##pathname) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_prlimit64 ['pid_t pid', 'unsigned int resource', 'const struct rlimit64 __user *new_rlim', 'struct rlimit64 __user *old_rlim']
#define locals_LINUX__ARM_sys_prlimit64(ctx, pref) \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##resource) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##new_rlim) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##old_rlim) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_prlimit64(ctx, pref) \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##resource) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##new_rlim) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##old_rlim) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_prlimit64(ctx, pref) \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##resource) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##new_rlim) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##old_rlim) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_name_to_handle_at ['int dfd', 'const char __user *name', 'struct file_handle __user *handle', 'int __user *mnt_id', 'int flag']
#define locals_LINUX__ARM_sys_name_to_handle_at(ctx, pref) \
	int32_t UNUSED(pref##dfd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##name) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##handle) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##mnt_id) = *(uint32_t *)((ctx)->args[3]); \
	int32_t UNUSED(pref##flag) = *(int32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_name_to_handle_at(ctx, pref) \
	int32_t &UNUSED(pref##dfd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##name) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##handle) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##mnt_id) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	int32_t &UNUSED(pref##flag) = *reinterpret_cast<int32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_name_to_handle_at(ctx, pref) \
	const int32_t &UNUSED(pref##dfd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##name) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##handle) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##mnt_id) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const int32_t &UNUSED(pref##flag) = *reinterpret_cast<const int32_t *>((ctx)->args[4]);
#endif

// long sys_open_by_handle_at ['int mountdirfd', 'struct file_handle __user *handle', 'int flags']
#define locals_LINUX__ARM_sys_open_by_handle_at(ctx, pref) \
	int32_t UNUSED(pref##mountdirfd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##handle) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_open_by_handle_at(ctx, pref) \
	int32_t &UNUSED(pref##mountdirfd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##handle) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_open_by_handle_at(ctx, pref) \
	const int32_t &UNUSED(pref##mountdirfd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##handle) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[2]);
#endif

// long sys_clock_adjtime ['clockid_t which_clock', 'struct timex __user *tx']
#define locals_LINUX__ARM_sys_clock_adjtime(ctx, pref) \
	uint32_t UNUSED(pref##which_clock) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##tx) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_clock_adjtime(ctx, pref) \
	uint32_t &UNUSED(pref##which_clock) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##tx) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_clock_adjtime(ctx, pref) \
	const uint32_t &UNUSED(pref##which_clock) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##tx) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_syncfs ['int fd']
#define locals_LINUX__ARM_sys_syncfs(ctx, pref) \
	int32_t UNUSED(pref##fd) = *(int32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_syncfs(ctx, pref) \
	int32_t &UNUSED(pref##fd) = *reinterpret_cast<int32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_syncfs(ctx, pref) \
	const int32_t &UNUSED(pref##fd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]);
#endif

// long sys_sendmmsg ['int fd', 'struct mmsghdr __user *msg', 'unsigned int vlen', 'unsigned flags']
#define locals_LINUX__ARM_sys_sendmmsg(ctx, pref) \
	int32_t UNUSED(pref##fd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##msg) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##vlen) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sendmmsg(ctx, pref) \
	int32_t &UNUSED(pref##fd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##msg) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##vlen) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_sendmmsg(ctx, pref) \
	const int32_t &UNUSED(pref##fd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##msg) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##vlen) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_setns ['int fd', 'int nstype']
#define locals_LINUX__ARM_sys_setns(ctx, pref) \
	int32_t UNUSED(pref##fd) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##nstype) = *(int32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_setns(ctx, pref) \
	int32_t &UNUSED(pref##fd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##nstype) = *reinterpret_cast<int32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_setns(ctx, pref) \
	const int32_t &UNUSED(pref##fd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##nstype) = *reinterpret_cast<const int32_t *>((ctx)->args[1]);
#endif

// long sys_process_vm_readv ['pid_t pid', 'const struct iovec __user *lvec', 'unsigned long liovcnt', 'const struct iovec __user *rvec', 'unsigned long riovcnt', 'unsigned long flags']
#define locals_LINUX__ARM_sys_process_vm_readv(ctx, pref) \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##lvec) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##liovcnt) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##rvec) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##riovcnt) = *(uint32_t *)((ctx)->args[4]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[5]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_process_vm_readv(ctx, pref) \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##lvec) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##liovcnt) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##rvec) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##riovcnt) = *reinterpret_cast<uint32_t *>((ctx)->args[4]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[5]);
#define creferences_LINUX__ARM_sys_process_vm_readv(ctx, pref) \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##lvec) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##liovcnt) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##rvec) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##riovcnt) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[5]);
#endif

// long sys_process_vm_writev ['pid_t pid', 'const struct iovec __user *lvec', 'unsigned long liovcnt', 'const struct iovec __user *rvec', 'unsigned long riovcnt', 'unsigned long flags']
#define locals_LINUX__ARM_sys_process_vm_writev(ctx, pref) \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##lvec) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##liovcnt) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##rvec) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##riovcnt) = *(uint32_t *)((ctx)->args[4]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[5]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_process_vm_writev(ctx, pref) \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##lvec) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##liovcnt) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##rvec) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##riovcnt) = *reinterpret_cast<uint32_t *>((ctx)->args[4]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[5]);
#define creferences_LINUX__ARM_sys_process_vm_writev(ctx, pref) \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##lvec) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##liovcnt) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##rvec) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##riovcnt) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[5]);
#endif

// long sys_kcmp ['pid_t pid1', 'pid_t pid2', 'int type', 'unsigned long idx1', 'unsigned long idx2']
#define locals_LINUX__ARM_sys_kcmp(ctx, pref) \
	uint32_t UNUSED(pref##pid1) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##pid2) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##type) = *(int32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##idx1) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##idx2) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_kcmp(ctx, pref) \
	uint32_t &UNUSED(pref##pid1) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##pid2) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##type) = *reinterpret_cast<int32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##idx1) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##idx2) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_kcmp(ctx, pref) \
	const uint32_t &UNUSED(pref##pid1) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##pid2) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##type) = *reinterpret_cast<const int32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##idx1) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##idx2) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_finit_module ['int fd', 'const char __user *uargs', 'int flags']
#define locals_LINUX__ARM_sys_finit_module(ctx, pref) \
	int32_t UNUSED(pref##fd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##uargs) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_finit_module(ctx, pref) \
	int32_t &UNUSED(pref##fd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##uargs) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_finit_module(ctx, pref) \
	const int32_t &UNUSED(pref##fd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##uargs) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[2]);
#endif

// long sys_sched_setattr ['pid_t pid', 'struct sched_attr __user *attr', 'unsigned int flags']
#define locals_LINUX__ARM_sys_sched_setattr(ctx, pref) \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##attr) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sched_setattr(ctx, pref) \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##attr) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_sched_setattr(ctx, pref) \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##attr) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_sched_getattr ['pid_t pid', 'struct sched_attr __user *attr', 'unsigned int size', 'unsigned int flags']
#define locals_LINUX__ARM_sys_sched_getattr(ctx, pref) \
	uint32_t UNUSED(pref##pid) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##attr) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##size) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_sched_getattr(ctx, pref) \
	uint32_t &UNUSED(pref##pid) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##attr) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##size) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_sched_getattr(ctx, pref) \
	const uint32_t &UNUSED(pref##pid) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##attr) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##size) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]);
#endif

// long sys_renameat2 ['int olddfd', 'const char __user *oldname', 'int newdfd', 'const char __user *newname', 'unsigned int flags']
#define locals_LINUX__ARM_sys_renameat2(ctx, pref) \
	int32_t UNUSED(pref##olddfd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##oldname) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##newdfd) = *(int32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##newname) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_renameat2(ctx, pref) \
	int32_t &UNUSED(pref##olddfd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##oldname) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##newdfd) = *reinterpret_cast<int32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##newname) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_renameat2(ctx, pref) \
	const int32_t &UNUSED(pref##olddfd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##oldname) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##newdfd) = *reinterpret_cast<const int32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##newname) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]);
#endif

// long sys_seccomp ['unsigned int op', 'unsigned int flags', 'const char __user *uargs']
#define locals_LINUX__ARM_sys_seccomp(ctx, pref) \
	uint32_t UNUSED(pref##op) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##uargs) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_seccomp(ctx, pref) \
	uint32_t &UNUSED(pref##op) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##uargs) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_seccomp(ctx, pref) \
	const uint32_t &UNUSED(pref##op) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##uargs) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_getrandom ['char __user *buf', 'size_t count', 'unsigned int flags']
#define locals_LINUX__ARM_sys_getrandom(ctx, pref) \
	uint32_t UNUSED(pref##buf) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##count) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_getrandom(ctx, pref) \
	uint32_t &UNUSED(pref##buf) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##count) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_getrandom(ctx, pref) \
	const uint32_t &UNUSED(pref##buf) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##count) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_memfd_create ['const char __user *uname_ptr', 'unsigned int flags']
#define locals_LINUX__ARM_sys_memfd_create(ctx, pref) \
	uint32_t UNUSED(pref##uname_ptr) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_memfd_create(ctx, pref) \
	uint32_t &UNUSED(pref##uname_ptr) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_memfd_create(ctx, pref) \
	const uint32_t &UNUSED(pref##uname_ptr) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_bpf ['int cmd', 'union bpf_attr *attr', 'unsigned int size']
#define locals_LINUX__ARM_sys_bpf(ctx, pref) \
	int32_t UNUSED(pref##cmd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##attr) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##size) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_bpf(ctx, pref) \
	int32_t &UNUSED(pref##cmd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##attr) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##size) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_bpf(ctx, pref) \
	const int32_t &UNUSED(pref##cmd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##attr) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##size) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long sys_execveat ['int dfd', 'const char __user *filename', 'const char __user *const __user *argv', 'const char __user *const __user *envp', 'int flags']
#define locals_LINUX__ARM_sys_execveat(ctx, pref) \
	int32_t UNUSED(pref##dfd) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##filename) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##argv) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##envp) = *(uint32_t *)((ctx)->args[3]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[4]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_execveat(ctx, pref) \
	int32_t &UNUSED(pref##dfd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##filename) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##argv) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##envp) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[4]);
#define creferences_LINUX__ARM_sys_execveat(ctx, pref) \
	const int32_t &UNUSED(pref##dfd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##filename) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##argv) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##envp) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[4]);
#endif

// long sys_userfaultfd ['int flags']
#define locals_LINUX__ARM_sys_userfaultfd(ctx, pref) \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_userfaultfd(ctx, pref) \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_userfaultfd(ctx, pref) \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[0]);
#endif

// long sys_membarrier ['int cmd', 'int flags']
#define locals_LINUX__ARM_sys_membarrier(ctx, pref) \
	int32_t UNUSED(pref##cmd) = *(int32_t *)((ctx)->args[0]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_membarrier(ctx, pref) \
	int32_t &UNUSED(pref##cmd) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_membarrier(ctx, pref) \
	const int32_t &UNUSED(pref##cmd) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[1]);
#endif

// long sys_mlock2 ['unsigned long start', 'size_t len', 'int flags']
#define locals_LINUX__ARM_sys_mlock2(ctx, pref) \
	uint32_t UNUSED(pref##start) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##len) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_mlock2(ctx, pref) \
	uint32_t &UNUSED(pref##start) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##len) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_sys_mlock2(ctx, pref) \
	const uint32_t &UNUSED(pref##start) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##len) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[2]);
#endif

// long sys_copy_file_range ['int fd_in', 'loff_t __user *off_in', 'int fd_out', 'loff_t __user *off_out', 'size_t len', 'unsigned int flags']
#define locals_LINUX__ARM_sys_copy_file_range(ctx, pref) \
	int32_t UNUSED(pref##fd_in) = *(int32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##off_in) = *(uint32_t *)((ctx)->args[1]); \
	int32_t UNUSED(pref##fd_out) = *(int32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##off_out) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##len) = *(uint32_t *)((ctx)->args[4]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[5]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_copy_file_range(ctx, pref) \
	int32_t &UNUSED(pref##fd_in) = *reinterpret_cast<int32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##off_in) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	int32_t &UNUSED(pref##fd_out) = *reinterpret_cast<int32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##off_out) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##len) = *reinterpret_cast<uint32_t *>((ctx)->args[4]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[5]);
#define creferences_LINUX__ARM_sys_copy_file_range(ctx, pref) \
	const int32_t &UNUSED(pref##fd_in) = *reinterpret_cast<const int32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##off_in) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const int32_t &UNUSED(pref##fd_out) = *reinterpret_cast<const int32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##off_out) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##len) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[5]);
#endif

// long sys_preadv2 ['unsigned long fd', 'const struct iovec __user *vec', 'unsigned long vlen', 'unsigned long pos_l', 'unsigned long pos_h', 'int flags']
#define locals_LINUX__ARM_sys_preadv2(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##vec) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##vlen) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##pos_l) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##pos_h) = *(uint32_t *)((ctx)->args[4]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[5]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_preadv2(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##vec) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##vlen) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##pos_l) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##pos_h) = *reinterpret_cast<uint32_t *>((ctx)->args[4]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[5]);
#define creferences_LINUX__ARM_sys_preadv2(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##vec) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##vlen) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##pos_l) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##pos_h) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[5]);
#endif

// long sys_pwritev2 ['unsigned long fd', 'const struct iovec __user *vec', 'unsigned long vlen', 'unsigned long pos_l', 'unsigned long pos_h', 'int flags']
#define locals_LINUX__ARM_sys_pwritev2(ctx, pref) \
	uint32_t UNUSED(pref##fd) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##vec) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##vlen) = *(uint32_t *)((ctx)->args[2]); \
	uint32_t UNUSED(pref##pos_l) = *(uint32_t *)((ctx)->args[3]); \
	uint32_t UNUSED(pref##pos_h) = *(uint32_t *)((ctx)->args[4]); \
	int32_t UNUSED(pref##flags) = *(int32_t *)((ctx)->args[5]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_pwritev2(ctx, pref) \
	uint32_t &UNUSED(pref##fd) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##vec) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##vlen) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	uint32_t &UNUSED(pref##pos_l) = *reinterpret_cast<uint32_t *>((ctx)->args[3]); \
	uint32_t &UNUSED(pref##pos_h) = *reinterpret_cast<uint32_t *>((ctx)->args[4]); \
	int32_t &UNUSED(pref##flags) = *reinterpret_cast<int32_t *>((ctx)->args[5]);
#define creferences_LINUX__ARM_sys_pwritev2(ctx, pref) \
	const uint32_t &UNUSED(pref##fd) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##vec) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##vlen) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const uint32_t &UNUSED(pref##pos_l) = *reinterpret_cast<const uint32_t *>((ctx)->args[3]); \
	const uint32_t &UNUSED(pref##pos_h) = *reinterpret_cast<const uint32_t *>((ctx)->args[4]); \
	const int32_t &UNUSED(pref##flags) = *reinterpret_cast<const int32_t *>((ctx)->args[5]);
#endif

// long sys_pkey_mprotect ['unsigned long start', 'size_t len', 'unsigned long prot', 'int pkey']
#define locals_LINUX__ARM_sys_pkey_mprotect(ctx, pref) \
	uint32_t UNUSED(pref##start) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##len) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##prot) = *(uint32_t *)((ctx)->args[2]); \
	int32_t UNUSED(pref##pkey) = *(int32_t *)((ctx)->args[3]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_pkey_mprotect(ctx, pref) \
	uint32_t &UNUSED(pref##start) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##len) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##prot) = *reinterpret_cast<uint32_t *>((ctx)->args[2]); \
	int32_t &UNUSED(pref##pkey) = *reinterpret_cast<int32_t *>((ctx)->args[3]);
#define creferences_LINUX__ARM_sys_pkey_mprotect(ctx, pref) \
	const uint32_t &UNUSED(pref##start) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##len) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##prot) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]); \
	const int32_t &UNUSED(pref##pkey) = *reinterpret_cast<const int32_t *>((ctx)->args[3]);
#endif

// long sys_pkey_alloc ['unsigned long flags', 'unsigned long init_val']
#define locals_LINUX__ARM_sys_pkey_alloc(ctx, pref) \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##init_val) = *(uint32_t *)((ctx)->args[1]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_pkey_alloc(ctx, pref) \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##init_val) = *reinterpret_cast<uint32_t *>((ctx)->args[1]);
#define creferences_LINUX__ARM_sys_pkey_alloc(ctx, pref) \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##init_val) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]);
#endif

// long sys_pkey_free ['int pkey']
#define locals_LINUX__ARM_sys_pkey_free(ctx, pref) \
	int32_t UNUSED(pref##pkey) = *(int32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_sys_pkey_free(ctx, pref) \
	int32_t &UNUSED(pref##pkey) = *reinterpret_cast<int32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_sys_pkey_free(ctx, pref) \
	const int32_t &UNUSED(pref##pkey) = *reinterpret_cast<const int32_t *>((ctx)->args[0]);
#endif

// long ARM_breakpoint ['void']
#undef locals_LINUX__ARM_ARM_breakpoint
#if defined(__cplusplus)
#undef references_LINUX__ARM_ARM_breakpoint
#endif

// long ARM_cacheflush ['unsigned long start', 'unsigned long end', 'unsigned long flags']
#define locals_LINUX__ARM_ARM_cacheflush(ctx, pref) \
	uint32_t UNUSED(pref##start) = *(uint32_t *)((ctx)->args[0]); \
	uint32_t UNUSED(pref##end) = *(uint32_t *)((ctx)->args[1]); \
	uint32_t UNUSED(pref##flags) = *(uint32_t *)((ctx)->args[2]);
#if defined(__cplusplus)
#define references_LINUX__ARM_ARM_cacheflush(ctx, pref) \
	uint32_t &UNUSED(pref##start) = *reinterpret_cast<uint32_t *>((ctx)->args[0]); \
	uint32_t &UNUSED(pref##end) = *reinterpret_cast<uint32_t *>((ctx)->args[1]); \
	uint32_t &UNUSED(pref##flags) = *reinterpret_cast<uint32_t *>((ctx)->args[2]);
#define creferences_LINUX__ARM_ARM_cacheflush(ctx, pref) \
	const uint32_t &UNUSED(pref##start) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]); \
	const uint32_t &UNUSED(pref##end) = *reinterpret_cast<const uint32_t *>((ctx)->args[1]); \
	const uint32_t &UNUSED(pref##flags) = *reinterpret_cast<const uint32_t *>((ctx)->args[2]);
#endif

// long ARM_user26_mode ['void']
#undef locals_LINUX__ARM_ARM_user26_mode
#if defined(__cplusplus)
#undef references_LINUX__ARM_ARM_user26_mode
#endif

// long ARM_usr32_mode ['void']
#undef locals_LINUX__ARM_ARM_usr32_mode
#if defined(__cplusplus)
#undef references_LINUX__ARM_ARM_usr32_mode
#endif

// long ARM_set_tls ['unsigned long arg']
#define locals_LINUX__ARM_ARM_set_tls(ctx, pref) \
	uint32_t UNUSED(pref##arg) = *(uint32_t *)((ctx)->args[0]);
#if defined(__cplusplus)
#define references_LINUX__ARM_ARM_set_tls(ctx, pref) \
	uint32_t &UNUSED(pref##arg) = *reinterpret_cast<uint32_t *>((ctx)->args[0]);
#define creferences_LINUX__ARM_ARM_set_tls(ctx, pref) \
	const uint32_t &UNUSED(pref##arg) = *reinterpret_cast<const uint32_t *>((ctx)->args[0]);
#endif


/* vim: set tabstop=4 softtabstop=4 noexpandtab ft=cpp: */