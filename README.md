<h1> <u> Abstract </u> </h1>

  This project is focused on the exploration and analysis of the operating system process API,
centering on the fork() function and its modern alternative, posix_spawn(). Drawing inspiration
from Baumann et al.'s 2019 work, "A fork() in a road," the project delves into the differences
between the mechanisms, functionalities, advantages, and disadvantages of fork() and
posix_spawn() in process creation code. It is motivated by existing research about the
performance, efficiency, and security issues that fork() poses to operating systems.
posix_spawn() is proposed as an alternative to fork(). This project aims to extend the proposed
posix_spawn() alternative of fork() to practical applications. Open-source software code that
involves process creation has been modified to leverage posix_spawn() for its performance,
security, and resource benefits over fork(). Through this practical code adaptation, posix_spawn()
is highlighted to have significant technical and functional implications and advantages for the
process API over fork().

<h1> Methods </h1>

To thoroughly understand differences in the performance, efficiency and usability of
fork() and posix_spawn(), the current project examines three separate open source softwares that
make use of fork() for software execution. These softwares were chosen based on whether
software code uses fork() in a way that is modifiable and adaptable to alternative functions (like
posix_spawn). After careful consideration of a range of softwares, the following three were
choses to undergo code adaptation for the purposes of this project:
1. Sash (the Super Awesome Shell): Sash is a small and simple POSIX shell that can
currently execute programs (Juliatto, 2019).
2. Toybox: Toybox is a Linux-based command-line interface that combines various
common Linux command line utilities into a single executable software (Landley, 2019).
3. Htop: Htop is a cross-platform interactive process viewer. It allows for users to scroll
along the list of processes vertically and horizontally to see their full command lines and
related information like memory and CPU consumption (Htop-Dev, 2020).

<h1> Procedures</h1>

Github repositories of the selected open-source softwares were manually parsed through
to understand the general purpose of the software. Simultaneously, software files within the
repositories were checked for use of fork(). After confirming the utilization of fork() to create
processes, ‘execute.c’ from Sash, ‘OpenFilesScreen.c’ from Htop, and ‘portability.c’ from
Toybox were chosen to undergo the fork() to posix_spawn() adaptation. Once code modification was completed, the
softwares were built and tested to ensure accuracy and consistency with previous behavior and
expected functionality. Testing showed accurate and consistent results, confirming the reliability
of the modified code.

<h1> Discussion </h1>
Alongside consistent program behavior, there were no significant differences in runtime
observed in the modified posix_spawn() code compared to the original fork() program. However, the code does have better portability and resource efficiency because posix_spawn() does not duplicate address space and is thus, more suitable for systems with limited resources or without full fork() support. Future research should focus on investigating differences between fork() and its other alternatives.
Baumann et al., 2019 introduced the idea of using vfork() and clone() as other potential
alternatives alongside posix_spawn(). While vfork() is only a variant of the typical fork(), it
creates a new process that shares the parent’s address space until the child calls exec(). This
would reduce the fork() cost of cloning the parent’s address space. clone()’s behavior is highly
similar to that of fork()’s but it provides more control over aspects of the child copy process.
Modifying the open-source softwares used in this project to instead use these alternatives would
allow researchers to explore the accessibility and usability of these functions. Researchers could
also perform run-time analysis on the different versions of the softwares that use different
process creation functions and identify the most optimal function for use in future software.

<h1> References </h1>

Baumann, A, Appavoo, J., Krieger, O., & Roscoe, T. (2019, May 13-15). A fork() in the road.
Workshop on Hot Topics in Operating Systems (HotOS ’19), Bertinoro, Italy. ACM, New
York, NY, USA. https://dl.acm.org/doi/10.1145/3317550.3321435

FORK(2) - Linux manual page. (n.d.). https://man7.org/linux/man-pages/man2/fork.2.html

Htop-Dev. (2020). Htop-dev/htop: Htop - an interactive process viewer. GitHub.
https://github.com/htop-dev/htop

Juliatto, V. F. (2019). VFabricio/Sash: A tiny POSIX shell, written in c. GitHub.
https://github.com/VFabricio/sash

Landley, R. (2019). Landley/Toybox: Toybox. GitHub. https://github.com/landley/toybox

POSIX_SPAWN(3) - linux manual page. (n.d.).
https://man7.org/linux/man-pages/man3/posix_spawn.3.html

What is an API? - application programming interface explained - AWS. (n.d.).
https://aws.amazon.com/what-is/api/
