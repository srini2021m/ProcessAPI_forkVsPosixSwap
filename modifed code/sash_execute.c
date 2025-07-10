//-----------------------------------------------------------------------------
//
// This source file is part of sash, the Super Awesome Shell
//
// Copyright (C) 2019, 2020 Vilson Fabricio Juliatto <vfabricio2201@gmail.com>
//
// This software is distributed under the terms of the AGPL v3.0 license.
// See the LICENSE file at the root of this project for more details.
//
//-----------------------------------------------------------------------------

#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "error.h"
#include "execute.h"
#include "lexer.h"
#include "wrappers.h"
#include <spawn.h>

void execute(tokens t) {
    if (t.n == 0) {
        error_quit(NO_COMMANDS_EXECUTE,
            "FATAL ERROR: Tried to run execute with an empty command!");
    }

    //parameters needed for posix_spawn
    pid_t pid; //process ID
    char *command = t.tokens_list[0]; //file or filepath
    char **args = t.tokens_list; //arguments
    posix_spawn_file_actions_t actions;
    posix_spawn_file_actions_init(&actions); //file actions

    //test cases for invalid accesses
    if (pid < 0) {
        if (errno == EAGAIN) {
            error_quit(MAX_THREADS_EXECUTE, "FATAL ERROR: cannot execute command because the maximum number of threads has been reached or forking is not allowed by the scheduling policy!");
        }
        if (errno == ENOMEM) {
            error_quit(OOM_EXECUTE, "FATAL ERROR: cannot execute command because the system is out of memory!");
        }
        if (errno == ENOSYS) {
            error_quit(NO_POSIX_EXECUTE, "FATAL ERROR: posix_spawn() is not avaiable on this platform!");
        }
        error_quit(UNKNOWN_ERROR, "FATAL ERROR: an unknown error ocurred while trying to run a command!");
    }

    //if posix_spawn() completes successfully, it would return 0
    //test case for invalid posix_spawn (wouldn't have created a valid child process)
    if (posix_spawn(&pid, command, &actions, NULL, args, NULL) != 0) {
        fprintf("posix_spawn", stderr);
        error_quit(UNKNOWN_ERROR, "FATAL ERROR: Failed to spawn process using posix_spawn!");
    }

    int status;

    //waiting for newly created process to return
    //if waitpid is successful, the created process returns
    if (waitpid(pid, &status, 0) == -1) {
        fprintf("waitpid", stderr);
        error_quit(UNKNOWN_ERROR, "FATAL ERROR: Failed to wait for spawned process!");
    }

    //handle the exit status of the created process
    if (WIFEXITED(status)) {
        printf("Spawned process exited with status %d\n", WEXITSTATUS(status));
    } else {
        printf("Spawned process did not exit normally\n");
    }

    posix_spawn_file_actions_destroy(&actions); //free resources related to file actions
}