# Operating Systems Experiments – VS Code / GitHub

This repository contains the code from Experiments 1–6 supplied in the OS laboratory PDFs.

## Requirements
- Visual Studio Code
- GCC (MinGW/MSYS2 on Windows, or GCC on Linux/Kali)
- Bash for shell scripts
- For Experiments 3, 5 and 6, use Linux/Kali/WSL or a Linux-compatible environment because they use POSIX system calls.

## Folder structure
- `01-installation-verification/` – OS verification commands
- `02-unix-shell-programming/` – UNIX commands and 8 shell programs
- `03-system-calls/` – fork, wait, getpid, exit and close examples
- `04-cpu-scheduling/` – FCFS, SJF, Priority and Round Robin
- `05-ipc-pipe/` – IPC using pipe
- `06-semaphore/` – semaphore mutual exclusion

## Running in VS Code

### C programs
Open the experiment folder in VS Code, open the integrated terminal, then:

```bash
gcc filename.c -o filename
./filename
```

On Windows with a suitable GCC installation, the executable may be run as:
```powershell
.ilename.exe
```

### Shell programs
Run on Linux/Kali/WSL:
```bash
chmod +x filename.sh
./filename.sh
```

### GitHub
Initialize and push the repository:
```bash
git init
git add .
git commit -m "Add OS lab experiments"
git branch -M main
git remote add origin <YOUR_GITHUB_REPOSITORY_URL>
git push -u origin main
```

Experiment 1 contains verification commands rather than a runnable program, matching the supplied PDF.
