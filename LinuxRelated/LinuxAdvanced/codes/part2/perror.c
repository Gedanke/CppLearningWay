#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDWR);
    if (fd < 0)
    {
        perror("open error");
        if (errno == ENOENT)
        {
            printf("same\n");
        }
        return -1;
    }

    int i = 0;
    for (i = 0; i < 64; i++)
    {
        errno = i;
        printf("%d: %s\n", i, strerror(errno));
    }

    /*
        0: Success
        1: Operation not permitted
        2: No such file or directory
        3: No such process
        4: Interrupted system call
        5: Input/output error
        6: No such device or address
        7: Argument list too long
        8: Exec format error
        9: Bad file descriptor
        10: No child processes
        11: Resource temporarily unavailable
        12: Cannot allocate memory
        13: Permission denied
        14: Bad address
        15: Block device required
        16: Device or resource busy
        17: File exists
        18: Invalid cross-device link
        19: No such device
        20: Not a directory
        21: Is a directory
        22: Invalid argument
        23: Too many open files in system
        24: Too many open files
        25: Inappropriate ioctl for device
        26: Text file busy
        27: File too large
        28: No space left on device
        29: Illegal seek
        30: Read-only file system
        31: Too many links
        32: Broken pipe
        33: Numerical argument out of domain
        34: Numerical result out of range
        35: Resource deadlock avoided
        36: File name too long
        37: No locks available
        38: Function not implemented
        39: Directory not empty
        40: Too many levels of symbolic links
        41: Unknown error 41
        42: No message of desired type
        43: Identifier removed
        44: Channel number out of range
        45: Level 2 not synchronized
        46: Level 3 halted
        47: Level 3 reset
        48: Link number out of range
        49: Protocol driver not attached
        50: No CSI structure available
        51: Level 2 halted
        52: Invalid exchange
        53: Invalid request descriptor
        54: Exchange full
        55: No anode
        56: Invalid request code
        57: Invalid slot
        58: Unknown error 58
        59: Bad font file format
        60: Device not a stream
        61: No data available
        62: Timer expired
        63: Out of streams resources
    */

    return 0;
}