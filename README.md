# Computah project

 - Bachelor thesis idea
 - Starting now, because it's... quite a big project

### What is it even!?

Very simple. I wanna make my own system, and by own, I mean the whole thing... other than the actual silicon, so that includes:
 - an operating system
 - computing hardware

...that's it basically. That's the two most important parts of a computer system.
<br>
But, I like to make stuff "mine" in some way, so it feels like it's my product, not just a copy-paste of someone other's work, that means that I will do these things:
 - something "novel" (doesn't actually need to be new, just niche, "mine")
 - design everything myself (mostly)
 - build and construct the hardware myself

### The actual plan

#### Operating System
I mentioned I wanna do something that feels "mine"... so I'm gonna do an operating system where almost everything is a register.
<br>
If Unix based systems are "everything is a file", then why couldn't I do an "everything is a register" system?
<br>
And since I'm coming from pure bare-metal programming background, this makes a lot of sense to me, to just have everything controlled through simple registers.
<br>
The concept is still in progress, but it would basically work similarly to what Linux does with VFS, but instead of files, it would be registers in virtual memory.


#### Hardware
I wanna start with simple QEMU emulations just to have a proof of concept for the OS, but later port it to actual hardware.
<br>
With actual hardware, I wanna go into 32 bit ARM, so cores like ARM Cortex-A7 will be perfect.
<br>
The actual CPU that I would use could be the Allwinner H3, the same that OrangePI is using, so lots of documentation and technical reference.
<br>
Then I would actually want to try designing my own board with the CPU, some RAM and either eMMC or just a SD card, or both.
