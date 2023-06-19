
test.out:     file format elf64-x86-64


Disassembly of section .interp:

0000000000400318 <.interp>:
  400318:	2f                   	(bad)
  400319:	6c                   	ins    BYTE PTR es:[rdi],dx
  40031a:	69 62 36 34 2f 6c 64 	imul   esp,DWORD PTR [rdx+0x36],0x646c2f34
  400321:	2d 6c 69 6e 75       	sub    eax,0x756e696c
  400326:	78 2d                	js     400355 <__abi_tag-0x27>
  400328:	78 38                	js     400362 <__abi_tag-0x1a>
  40032a:	36 2d 36 34 2e 73    	ss sub eax,0x732e3436
  400330:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  400331:	2e 32 00             	cs xor al,BYTE PTR [rax]

Disassembly of section .note.gnu.property:

0000000000400338 <.note.gnu.property>:
  400338:	04 00                	add    al,0x0
  40033a:	00 00                	add    BYTE PTR [rax],al
  40033c:	10 00                	adc    BYTE PTR [rax],al
  40033e:	00 00                	add    BYTE PTR [rax],al
  400340:	05 00 00 00 47       	add    eax,0x47000000
  400345:	4e 55                	rex.WRX push rbp
  400347:	00 02                	add    BYTE PTR [rdx],al
  400349:	80 00 c0             	add    BYTE PTR [rax],0xc0
  40034c:	04 00                	add    al,0x0
  40034e:	00 00                	add    BYTE PTR [rax],al
  400350:	01 00                	add    DWORD PTR [rax],eax
  400352:	00 00                	add    BYTE PTR [rax],al
  400354:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .note.gnu.build-id:

0000000000400358 <.note.gnu.build-id>:
  400358:	04 00                	add    al,0x0
  40035a:	00 00                	add    BYTE PTR [rax],al
  40035c:	14 00                	adc    al,0x0
  40035e:	00 00                	add    BYTE PTR [rax],al
  400360:	03 00                	add    eax,DWORD PTR [rax]
  400362:	00 00                	add    BYTE PTR [rax],al
  400364:	47                   	rex.RXB
  400365:	4e 55                	rex.WRX push rbp
  400367:	00 f2                	add    dl,dh
  400369:	6c                   	ins    BYTE PTR es:[rdi],dx
  40036a:	1f                   	(bad)
  40036b:	dc ff                	fdiv   st(7),st
  40036d:	12 cc                	adc    cl,ah
  40036f:	b9 38 cd 50 7d       	mov    ecx,0x7d50cd38
  400374:	47 d1 48 76          	rex.RXB ror DWORD PTR [r8+0x76],1
  400378:	44 d7                	rex.R xlat BYTE PTR ds:[rbx]
  40037a:	cd 4b                	int    0x4b

Disassembly of section .note.ABI-tag:

000000000040037c <__abi_tag>:
  40037c:	04 00                	add    al,0x0
  40037e:	00 00                	add    BYTE PTR [rax],al
  400380:	10 00                	adc    BYTE PTR [rax],al
  400382:	00 00                	add    BYTE PTR [rax],al
  400384:	01 00                	add    DWORD PTR [rax],eax
  400386:	00 00                	add    BYTE PTR [rax],al
  400388:	47                   	rex.RXB
  400389:	4e 55                	rex.WRX push rbp
  40038b:	00 00                	add    BYTE PTR [rax],al
  40038d:	00 00                	add    BYTE PTR [rax],al
  40038f:	00 03                	add    BYTE PTR [rbx],al
  400391:	00 00                	add    BYTE PTR [rax],al
  400393:	00 02                	add    BYTE PTR [rdx],al
  400395:	00 00                	add    BYTE PTR [rax],al
  400397:	00 00                	add    BYTE PTR [rax],al
  400399:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .gnu.hash:

00000000004003a0 <.gnu.hash>:
  4003a0:	01 00                	add    DWORD PTR [rax],eax
  4003a2:	00 00                	add    BYTE PTR [rax],al
  4003a4:	01 00                	add    DWORD PTR [rax],eax
  4003a6:	00 00                	add    BYTE PTR [rax],al
  4003a8:	01 00                	add    DWORD PTR [rax],eax
	...

Disassembly of section .dynsym:

00000000004003c0 <.dynsym>:
	...
  4003d8:	0b 00                	or     eax,DWORD PTR [rax]
  4003da:	00 00                	add    BYTE PTR [rax],al
  4003dc:	12 00                	adc    al,BYTE PTR [rax]
	...
  4003ee:	00 00                	add    BYTE PTR [rax],al
  4003f0:	01 00                	add    DWORD PTR [rax],eax
  4003f2:	00 00                	add    BYTE PTR [rax],al
  4003f4:	12 00                	adc    al,BYTE PTR [rax]
	...
  400406:	00 00                	add    BYTE PTR [rax],al
  400408:	3e 00 00             	ds add BYTE PTR [rax],al
  40040b:	00 20                	add    BYTE PTR [rax],ah
	...
  40041d:	00 00                	add    BYTE PTR [rax],al
  40041f:	00 06                	add    BYTE PTR [rsi],al
  400421:	00 00                	add    BYTE PTR [rax],al
  400423:	00 12                	add    BYTE PTR [rdx],dl
	...

Disassembly of section .dynstr:

0000000000400438 <.dynstr>:
  400438:	00 70 75             	add    BYTE PTR [rax+0x75],dh
  40043b:	74 73                	je     4004b0 <__abi_tag+0x134>
  40043d:	00 67 65             	add    BYTE PTR [rdi+0x65],ah
  400440:	74 73                	je     4004b5 <__abi_tag+0x139>
  400442:	00 5f 5f             	add    BYTE PTR [rdi+0x5f],bl
  400445:	6c                   	ins    BYTE PTR es:[rdi],dx
  400446:	69 62 63 5f 73 74 61 	imul   esp,DWORD PTR [rdx+0x63],0x6174735f
  40044d:	72 74                	jb     4004c3 <__abi_tag+0x147>
  40044f:	5f                   	pop    rdi
  400450:	6d                   	ins    DWORD PTR es:[rdi],dx
  400451:	61                   	(bad)
  400452:	69 6e 00 6c 69 62 63 	imul   ebp,DWORD PTR [rsi+0x0],0x6362696c
  400459:	2e 73 6f             	cs jae 4004cb <__abi_tag+0x14f>
  40045c:	2e 36 00 47 4c       	cs ss add BYTE PTR [rdi+0x4c],al
  400461:	49                   	rex.WB
  400462:	42                   	rex.X
  400463:	43 5f                	rex.XB pop r15
  400465:	32 2e                	xor    ch,BYTE PTR [rsi]
  400467:	32 2e                	xor    ch,BYTE PTR [rsi]
  400469:	35 00 47 4c 49       	xor    eax,0x494c4700
  40046e:	42                   	rex.X
  40046f:	43 5f                	rex.XB pop r15
  400471:	32 2e                	xor    ch,BYTE PTR [rsi]
  400473:	33 34 00             	xor    esi,DWORD PTR [rax+rax*1]
  400476:	5f                   	pop    rdi
  400477:	5f                   	pop    rdi
  400478:	67 6d                	ins    DWORD PTR es:[edi],dx
  40047a:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  40047b:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  40047c:	5f                   	pop    rdi
  40047d:	73 74                	jae    4004f3 <__abi_tag+0x177>
  40047f:	61                   	(bad)
  400480:	72 74                	jb     4004f6 <__abi_tag+0x17a>
  400482:	5f                   	pop    rdi
  400483:	5f                   	pop    rdi
	...

Disassembly of section .gnu.version:

0000000000400486 <.gnu.version>:
  400486:	00 00                	add    BYTE PTR [rax],al
  400488:	02 00                	add    al,BYTE PTR [rax]
  40048a:	03 00                	add    eax,DWORD PTR [rax]
  40048c:	01 00                	add    DWORD PTR [rax],eax
  40048e:	03 00                	add    eax,DWORD PTR [rax]

Disassembly of section .gnu.version_r:

0000000000400490 <.gnu.version_r>:
  400490:	01 00                	add    DWORD PTR [rax],eax
  400492:	02 00                	add    al,BYTE PTR [rax]
  400494:	1d 00 00 00 10       	sbb    eax,0x10000000
  400499:	00 00                	add    BYTE PTR [rax],al
  40049b:	00 00                	add    BYTE PTR [rax],al
  40049d:	00 00                	add    BYTE PTR [rax],al
  40049f:	00 75 1a             	add    BYTE PTR [rbp+0x1a],dh
  4004a2:	69 09 00 00 03 00    	imul   ecx,DWORD PTR [rcx],0x30000
  4004a8:	27                   	(bad)
  4004a9:	00 00                	add    BYTE PTR [rax],al
  4004ab:	00 10                	add    BYTE PTR [rax],dl
  4004ad:	00 00                	add    BYTE PTR [rax],al
  4004af:	00 b4 91 96 06 00 00 	add    BYTE PTR [rcx+rdx*4+0x696],dh
  4004b6:	02 00                	add    al,BYTE PTR [rax]
  4004b8:	33 00                	xor    eax,DWORD PTR [rax]
  4004ba:	00 00                	add    BYTE PTR [rax],al
  4004bc:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .rela.dyn:

00000000004004c0 <.rela.dyn>:
  4004c0:	d8 3f                	fdivr  DWORD PTR [rdi]
  4004c2:	40 00 00             	rex add BYTE PTR [rax],al
  4004c5:	00 00                	add    BYTE PTR [rax],al
  4004c7:	00 06                	add    BYTE PTR [rsi],al
  4004c9:	00 00                	add    BYTE PTR [rax],al
  4004cb:	00 01                	add    BYTE PTR [rcx],al
	...
  4004d5:	00 00                	add    BYTE PTR [rax],al
  4004d7:	00 e0                	add    al,ah
  4004d9:	3f                   	(bad)
  4004da:	40 00 00             	rex add BYTE PTR [rax],al
  4004dd:	00 00                	add    BYTE PTR [rax],al
  4004df:	00 06                	add    BYTE PTR [rsi],al
  4004e1:	00 00                	add    BYTE PTR [rax],al
  4004e3:	00 03                	add    BYTE PTR [rbx],al
	...

Disassembly of section .rela.plt:

00000000004004f0 <.rela.plt>:
  4004f0:	00 40 40             	add    BYTE PTR [rax+0x40],al
  4004f3:	00 00                	add    BYTE PTR [rax],al
  4004f5:	00 00                	add    BYTE PTR [rax],al
  4004f7:	00 07                	add    BYTE PTR [rdi],al
  4004f9:	00 00                	add    BYTE PTR [rax],al
  4004fb:	00 02                	add    BYTE PTR [rdx],al
	...
  400505:	00 00                	add    BYTE PTR [rax],al
  400507:	00 08                	add    BYTE PTR [rax],cl
  400509:	40                   	rex
  40050a:	40 00 00             	rex add BYTE PTR [rax],al
  40050d:	00 00                	add    BYTE PTR [rax],al
  40050f:	00 07                	add    BYTE PTR [rdi],al
  400511:	00 00                	add    BYTE PTR [rax],al
  400513:	00 04 00             	add    BYTE PTR [rax+rax*1],al
	...

Disassembly of section .init:

0000000000401000 <_init>:
  401000:	48 83 ec 08          	sub    rsp,0x8
  401004:	48 8b 05 d5 2f 00 00 	mov    rax,QWORD PTR [rip+0x2fd5]        # 403fe0 <__gmon_start__@Base>
  40100b:	48 85 c0             	test   rax,rax
  40100e:	74 02                	je     401012 <_init+0x12>
  401010:	ff d0                	call   rax
  401012:	48 83 c4 08          	add    rsp,0x8
  401016:	c3                   	ret

Disassembly of section .plt:

0000000000401020 <puts@plt-0x10>:
  401020:	ff 35 ca 2f 00 00    	push   QWORD PTR [rip+0x2fca]        # 403ff0 <_GLOBAL_OFFSET_TABLE_+0x8>
  401026:	ff 25 cc 2f 00 00    	jmp    QWORD PTR [rip+0x2fcc]        # 403ff8 <_GLOBAL_OFFSET_TABLE_+0x10>
  40102c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000401030 <puts@plt>:
  401030:	ff 25 ca 2f 00 00    	jmp    QWORD PTR [rip+0x2fca]        # 404000 <puts@GLIBC_2.2.5>
  401036:	68 00 00 00 00       	push   0x0
  40103b:	e9 e0 ff ff ff       	jmp    401020 <_init+0x20>

0000000000401040 <gets@plt>:
  401040:	ff 25 c2 2f 00 00    	jmp    QWORD PTR [rip+0x2fc2]        # 404008 <gets@GLIBC_2.2.5>
  401046:	68 01 00 00 00       	push   0x1
  40104b:	e9 d0 ff ff ff       	jmp    401020 <_init+0x20>

Disassembly of section .text:

0000000000401050 <_start>:
  401050:	31 ed                	xor    ebp,ebp
  401052:	49 89 d1             	mov    r9,rdx
  401055:	5e                   	pop    rsi
  401056:	48 89 e2             	mov    rdx,rsp
  401059:	48 83 e4 f0          	and    rsp,0xfffffffffffffff0
  40105d:	50                   	push   rax
  40105e:	54                   	push   rsp
  40105f:	45 31 c0             	xor    r8d,r8d
  401062:	31 c9                	xor    ecx,ecx
  401064:	48 c7 c7 4c 11 40 00 	mov    rdi,0x40114c
  40106b:	ff 15 67 2f 00 00    	call   QWORD PTR [rip+0x2f67]        # 403fd8 <__libc_start_main@GLIBC_2.34>
  401071:	f4                   	hlt
  401072:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
  401079:	00 00 00 
  40107c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000401080 <_dl_relocate_static_pie>:
  401080:	c3                   	ret
  401081:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
  401088:	00 00 00 
  40108b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000401090 <deregister_tm_clones>:
  401090:	b8 20 40 40 00       	mov    eax,0x404020
  401095:	48 3d 20 40 40 00    	cmp    rax,0x404020
  40109b:	74 13                	je     4010b0 <deregister_tm_clones+0x20>
  40109d:	b8 00 00 00 00       	mov    eax,0x0
  4010a2:	48 85 c0             	test   rax,rax
  4010a5:	74 09                	je     4010b0 <deregister_tm_clones+0x20>
  4010a7:	bf 20 40 40 00       	mov    edi,0x404020
  4010ac:	ff e0                	jmp    rax
  4010ae:	66 90                	xchg   ax,ax
  4010b0:	c3                   	ret
  4010b1:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
  4010b8:	00 00 00 00 
  4010bc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

00000000004010c0 <register_tm_clones>:
  4010c0:	be 20 40 40 00       	mov    esi,0x404020
  4010c5:	48 81 ee 20 40 40 00 	sub    rsi,0x404020
  4010cc:	48 89 f0             	mov    rax,rsi
  4010cf:	48 c1 ee 3f          	shr    rsi,0x3f
  4010d3:	48 c1 f8 03          	sar    rax,0x3
  4010d7:	48 01 c6             	add    rsi,rax
  4010da:	48 d1 fe             	sar    rsi,1
  4010dd:	74 11                	je     4010f0 <register_tm_clones+0x30>
  4010df:	b8 00 00 00 00       	mov    eax,0x0
  4010e4:	48 85 c0             	test   rax,rax
  4010e7:	74 07                	je     4010f0 <register_tm_clones+0x30>
  4010e9:	bf 20 40 40 00       	mov    edi,0x404020
  4010ee:	ff e0                	jmp    rax
  4010f0:	c3                   	ret
  4010f1:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
  4010f8:	00 00 00 00 
  4010fc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000401100 <__do_global_dtors_aux>:
  401100:	f3 0f 1e fa          	endbr64
  401104:	80 3d 15 2f 00 00 00 	cmp    BYTE PTR [rip+0x2f15],0x0        # 404020 <__TMC_END__>
  40110b:	75 13                	jne    401120 <__do_global_dtors_aux+0x20>
  40110d:	55                   	push   rbp
  40110e:	48 89 e5             	mov    rbp,rsp
  401111:	e8 7a ff ff ff       	call   401090 <deregister_tm_clones>
  401116:	c6 05 03 2f 00 00 01 	mov    BYTE PTR [rip+0x2f03],0x1        # 404020 <__TMC_END__>
  40111d:	5d                   	pop    rbp
  40111e:	c3                   	ret
  40111f:	90                   	nop
  401120:	c3                   	ret
  401121:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
  401128:	00 00 00 00 
  40112c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000401130 <frame_dummy>:
  401130:	f3 0f 1e fa          	endbr64
  401134:	eb 8a                	jmp    4010c0 <register_tm_clones>

0000000000401136 <test_function>:
  401136:	55                   	push   rbp
  401137:	48 89 e5             	mov    rbp,rsp
  40113a:	48 8d 05 c3 0e 00 00 	lea    rax,[rip+0xec3]        # 402004 <_IO_stdin_used+0x4>
  401141:	48 89 c7             	mov    rdi,rax
  401144:	e8 e7 fe ff ff       	call   401030 <puts@plt>
  401149:	90                   	nop
  40114a:	5d                   	pop    rbp
  40114b:	c3                   	ret

000000000040114c <main>:
  40114c:	55                   	push   rbp
  40114d:	48 89 e5             	mov    rbp,rsp
  401150:	48 83 c4 80          	add    rsp,0xffffffffffffff80
  401154:	c6 45 80 41          	mov    BYTE PTR [rbp-0x80],0x41
  401158:	b8 00 00 00 00       	mov    eax,0x0
  40115d:	e8 d4 ff ff ff       	call   401136 <test_function>
  401162:	48 8d 45 80          	lea    rax,[rbp-0x80]
  401166:	48 89 c7             	mov    rdi,rax
  401169:	b8 00 00 00 00       	mov    eax,0x0
  40116e:	e8 cd fe ff ff       	call   401040 <gets@plt>
  401173:	48 8d 45 80          	lea    rax,[rbp-0x80]
  401177:	48 89 c7             	mov    rdi,rax
  40117a:	e8 b1 fe ff ff       	call   401030 <puts@plt>
  40117f:	b8 00 00 00 00       	mov    eax,0x0
  401184:	c9                   	leave
  401185:	c3                   	ret

Disassembly of section .fini:

0000000000401188 <_fini>:
  401188:	48 83 ec 08          	sub    rsp,0x8
  40118c:	48 83 c4 08          	add    rsp,0x8
  401190:	c3                   	ret

Disassembly of section .rodata:

0000000000402000 <_IO_stdin_used>:
  402000:	01 00                	add    DWORD PTR [rax],eax
  402002:	02 00                	add    al,BYTE PTR [rax]
  402004:	48                   	rex.W
  402005:	65 6c                	gs ins BYTE PTR es:[rdi],dx
  402007:	6c                   	ins    BYTE PTR es:[rdi],dx
  402008:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  402009:	20 57 6f             	and    BYTE PTR [rdi+0x6f],dl
  40200c:	72 6c                	jb     40207a <__GNU_EH_FRAME_HDR+0x66>
  40200e:	64 21 00             	and    DWORD PTR fs:[rax],eax

Disassembly of section .eh_frame_hdr:

0000000000402014 <__GNU_EH_FRAME_HDR>:
  402014:	01 1b                	add    DWORD PTR [rbx],ebx
  402016:	03 3b                	add    edi,DWORD PTR [rbx]
  402018:	30 00                	xor    BYTE PTR [rax],al
  40201a:	00 00                	add    BYTE PTR [rax],al
  40201c:	05 00 00 00 0c       	add    eax,0xc000000
  402021:	f0 ff                	lock (bad)
  402023:	ff 8c 00 00 00 3c f0 	dec    DWORD PTR [rax+rax*1-0xfc40000]
  40202a:	ff                   	(bad)
  40202b:	ff 4c 00 00          	dec    DWORD PTR [rax+rax*1+0x0]
  40202f:	00 6c f0 ff          	add    BYTE PTR [rax+rsi*8-0x1],ch
  402033:	ff                   	(bad)
  402034:	78 00                	js     402036 <__GNU_EH_FRAME_HDR+0x22>
  402036:	00 00                	add    BYTE PTR [rax],al
  402038:	22 f1                	and    dh,cl
  40203a:	ff                   	(bad)
  40203b:	ff b4 00 00 00 38 f1 	push   QWORD PTR [rax+rax*1-0xec80000]
  402042:	ff                   	(bad)
  402043:	ff d4                	call   rsp
  402045:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .eh_frame:

0000000000402048 <__FRAME_END__-0xc0>:
  402048:	14 00                	adc    al,0x0
  40204a:	00 00                	add    BYTE PTR [rax],al
  40204c:	00 00                	add    BYTE PTR [rax],al
  40204e:	00 00                	add    BYTE PTR [rax],al
  402050:	01 7a 52             	add    DWORD PTR [rdx+0x52],edi
  402053:	00 01                	add    BYTE PTR [rcx],al
  402055:	78 10                	js     402067 <__GNU_EH_FRAME_HDR+0x53>
  402057:	01 1b                	add    DWORD PTR [rbx],ebx
  402059:	0c 07                	or     al,0x7
  40205b:	08 90 01 07 10 10    	or     BYTE PTR [rax+0x10100701],dl
  402061:	00 00                	add    BYTE PTR [rax],al
  402063:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
  402066:	00 00                	add    BYTE PTR [rax],al
  402068:	e8 ef ff ff 22       	call   2340205c <_end+0x22ffe034>
  40206d:	00 00                	add    BYTE PTR [rax],al
  40206f:	00 00                	add    BYTE PTR [rax],al
  402071:	00 00                	add    BYTE PTR [rax],al
  402073:	00 14 00             	add    BYTE PTR [rax+rax*1],dl
  402076:	00 00                	add    BYTE PTR [rax],al
  402078:	00 00                	add    BYTE PTR [rax],al
  40207a:	00 00                	add    BYTE PTR [rax],al
  40207c:	01 7a 52             	add    DWORD PTR [rdx+0x52],edi
  40207f:	00 01                	add    BYTE PTR [rcx],al
  402081:	78 10                	js     402093 <__GNU_EH_FRAME_HDR+0x7f>
  402083:	01 1b                	add    DWORD PTR [rbx],ebx
  402085:	0c 07                	or     al,0x7
  402087:	08 90 01 00 00 10    	or     BYTE PTR [rax+0x10000001],dl
  40208d:	00 00                	add    BYTE PTR [rax],al
  40208f:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
  402092:	00 00                	add    BYTE PTR [rax],al
  402094:	ec                   	in     al,dx
  402095:	ef                   	out    dx,eax
  402096:	ff                   	(bad)
  402097:	ff 01                	inc    DWORD PTR [rcx]
  402099:	00 00                	add    BYTE PTR [rax],al
  40209b:	00 00                	add    BYTE PTR [rax],al
  40209d:	00 00                	add    BYTE PTR [rax],al
  40209f:	00 24 00             	add    BYTE PTR [rax+rax*1],ah
  4020a2:	00 00                	add    BYTE PTR [rax],al
  4020a4:	30 00                	xor    BYTE PTR [rax],al
  4020a6:	00 00                	add    BYTE PTR [rax],al
  4020a8:	78 ef                	js     402099 <__GNU_EH_FRAME_HDR+0x85>
  4020aa:	ff                   	(bad)
  4020ab:	ff 30                	push   QWORD PTR [rax]
  4020ad:	00 00                	add    BYTE PTR [rax],al
  4020af:	00 00                	add    BYTE PTR [rax],al
  4020b1:	0e                   	(bad)
  4020b2:	10 46 0e             	adc    BYTE PTR [rsi+0xe],al
  4020b5:	18 4a 0f             	sbb    BYTE PTR [rdx+0xf],cl
  4020b8:	0b 77 08             	or     esi,DWORD PTR [rdi+0x8]
  4020bb:	80 00 3f             	add    BYTE PTR [rax],0x3f
  4020be:	1a 3b                	sbb    bh,BYTE PTR [rbx]
  4020c0:	2a 33                	sub    dh,BYTE PTR [rbx]
  4020c2:	24 22                	and    al,0x22
  4020c4:	00 00                	add    BYTE PTR [rax],al
  4020c6:	00 00                	add    BYTE PTR [rax],al
  4020c8:	1c 00                	sbb    al,0x0
  4020ca:	00 00                	add    BYTE PTR [rax],al
  4020cc:	58                   	pop    rax
  4020cd:	00 00                	add    BYTE PTR [rax],al
  4020cf:	00 66 f0             	add    BYTE PTR [rsi-0x10],ah
  4020d2:	ff                   	(bad)
  4020d3:	ff 16                	call   QWORD PTR [rsi]
  4020d5:	00 00                	add    BYTE PTR [rax],al
  4020d7:	00 00                	add    BYTE PTR [rax],al
  4020d9:	41 0e                	rex.B (bad)
  4020db:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
  4020e1:	51                   	push   rcx
  4020e2:	0c 07                	or     al,0x7
  4020e4:	08 00                	or     BYTE PTR [rax],al
  4020e6:	00 00                	add    BYTE PTR [rax],al
  4020e8:	1c 00                	sbb    al,0x0
  4020ea:	00 00                	add    BYTE PTR [rax],al
  4020ec:	78 00                	js     4020ee <__GNU_EH_FRAME_HDR+0xda>
  4020ee:	00 00                	add    BYTE PTR [rax],al
  4020f0:	5c                   	pop    rsp
  4020f1:	f0 ff                	lock (bad)
  4020f3:	ff                   	(bad)
  4020f4:	3a 00                	cmp    al,BYTE PTR [rax]
  4020f6:	00 00                	add    BYTE PTR [rax],al
  4020f8:	00 41 0e             	add    BYTE PTR [rcx+0xe],al
  4020fb:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
  402101:	75 0c                	jne    40210f <__FRAME_END__+0x7>
  402103:	07                   	(bad)
  402104:	08 00                	or     BYTE PTR [rax],al
	...

0000000000402108 <__FRAME_END__>:
  402108:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .init_array:

0000000000403df8 <__frame_dummy_init_array_entry>:
  403df8:	30 11                	xor    BYTE PTR [rcx],dl
  403dfa:	40 00 00             	rex add BYTE PTR [rax],al
  403dfd:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .fini_array:

0000000000403e00 <__do_global_dtors_aux_fini_array_entry>:
  403e00:	00 11                	add    BYTE PTR [rcx],dl
  403e02:	40 00 00             	rex add BYTE PTR [rax],al
  403e05:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .dynamic:

0000000000403e08 <_DYNAMIC>:
  403e08:	01 00                	add    DWORD PTR [rax],eax
  403e0a:	00 00                	add    BYTE PTR [rax],al
  403e0c:	00 00                	add    BYTE PTR [rax],al
  403e0e:	00 00                	add    BYTE PTR [rax],al
  403e10:	1d 00 00 00 00       	sbb    eax,0x0
  403e15:	00 00                	add    BYTE PTR [rax],al
  403e17:	00 0c 00             	add    BYTE PTR [rax+rax*1],cl
  403e1a:	00 00                	add    BYTE PTR [rax],al
  403e1c:	00 00                	add    BYTE PTR [rax],al
  403e1e:	00 00                	add    BYTE PTR [rax],al
  403e20:	00 10                	add    BYTE PTR [rax],dl
  403e22:	40 00 00             	rex add BYTE PTR [rax],al
  403e25:	00 00                	add    BYTE PTR [rax],al
  403e27:	00 0d 00 00 00 00    	add    BYTE PTR [rip+0x0],cl        # 403e2d <_DYNAMIC+0x25>
  403e2d:	00 00                	add    BYTE PTR [rax],al
  403e2f:	00 88 11 40 00 00    	add    BYTE PTR [rax+0x4011],cl
  403e35:	00 00                	add    BYTE PTR [rax],al
  403e37:	00 19                	add    BYTE PTR [rcx],bl
  403e39:	00 00                	add    BYTE PTR [rax],al
  403e3b:	00 00                	add    BYTE PTR [rax],al
  403e3d:	00 00                	add    BYTE PTR [rax],al
  403e3f:	00 f8                	add    al,bh
  403e41:	3d 40 00 00 00       	cmp    eax,0x40
  403e46:	00 00                	add    BYTE PTR [rax],al
  403e48:	1b 00                	sbb    eax,DWORD PTR [rax]
  403e4a:	00 00                	add    BYTE PTR [rax],al
  403e4c:	00 00                	add    BYTE PTR [rax],al
  403e4e:	00 00                	add    BYTE PTR [rax],al
  403e50:	08 00                	or     BYTE PTR [rax],al
  403e52:	00 00                	add    BYTE PTR [rax],al
  403e54:	00 00                	add    BYTE PTR [rax],al
  403e56:	00 00                	add    BYTE PTR [rax],al
  403e58:	1a 00                	sbb    al,BYTE PTR [rax]
  403e5a:	00 00                	add    BYTE PTR [rax],al
  403e5c:	00 00                	add    BYTE PTR [rax],al
  403e5e:	00 00                	add    BYTE PTR [rax],al
  403e60:	00 3e                	add    BYTE PTR [rsi],bh
  403e62:	40 00 00             	rex add BYTE PTR [rax],al
  403e65:	00 00                	add    BYTE PTR [rax],al
  403e67:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
  403e6a:	00 00                	add    BYTE PTR [rax],al
  403e6c:	00 00                	add    BYTE PTR [rax],al
  403e6e:	00 00                	add    BYTE PTR [rax],al
  403e70:	08 00                	or     BYTE PTR [rax],al
  403e72:	00 00                	add    BYTE PTR [rax],al
  403e74:	00 00                	add    BYTE PTR [rax],al
  403e76:	00 00                	add    BYTE PTR [rax],al
  403e78:	f5                   	cmc
  403e79:	fe                   	(bad)
  403e7a:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
  403e7d:	00 00                	add    BYTE PTR [rax],al
  403e7f:	00 a0 03 40 00 00    	add    BYTE PTR [rax+0x4003],ah
  403e85:	00 00                	add    BYTE PTR [rax],al
  403e87:	00 05 00 00 00 00    	add    BYTE PTR [rip+0x0],al        # 403e8d <_DYNAMIC+0x85>
  403e8d:	00 00                	add    BYTE PTR [rax],al
  403e8f:	00 38                	add    BYTE PTR [rax],bh
  403e91:	04 40                	add    al,0x40
  403e93:	00 00                	add    BYTE PTR [rax],al
  403e95:	00 00                	add    BYTE PTR [rax],al
  403e97:	00 06                	add    BYTE PTR [rsi],al
  403e99:	00 00                	add    BYTE PTR [rax],al
  403e9b:	00 00                	add    BYTE PTR [rax],al
  403e9d:	00 00                	add    BYTE PTR [rax],al
  403e9f:	00 c0                	add    al,al
  403ea1:	03 40 00             	add    eax,DWORD PTR [rax+0x0]
  403ea4:	00 00                	add    BYTE PTR [rax],al
  403ea6:	00 00                	add    BYTE PTR [rax],al
  403ea8:	0a 00                	or     al,BYTE PTR [rax]
  403eaa:	00 00                	add    BYTE PTR [rax],al
  403eac:	00 00                	add    BYTE PTR [rax],al
  403eae:	00 00                	add    BYTE PTR [rax],al
  403eb0:	4d 00 00             	rex.WRB add BYTE PTR [r8],r8b
  403eb3:	00 00                	add    BYTE PTR [rax],al
  403eb5:	00 00                	add    BYTE PTR [rax],al
  403eb7:	00 0b                	add    BYTE PTR [rbx],cl
  403eb9:	00 00                	add    BYTE PTR [rax],al
  403ebb:	00 00                	add    BYTE PTR [rax],al
  403ebd:	00 00                	add    BYTE PTR [rax],al
  403ebf:	00 18                	add    BYTE PTR [rax],bl
  403ec1:	00 00                	add    BYTE PTR [rax],al
  403ec3:	00 00                	add    BYTE PTR [rax],al
  403ec5:	00 00                	add    BYTE PTR [rax],al
  403ec7:	00 15 00 00 00 00    	add    BYTE PTR [rip+0x0],dl        # 403ecd <_DYNAMIC+0xc5>
	...
  403ed5:	00 00                	add    BYTE PTR [rax],al
  403ed7:	00 03                	add    BYTE PTR [rbx],al
  403ed9:	00 00                	add    BYTE PTR [rax],al
  403edb:	00 00                	add    BYTE PTR [rax],al
  403edd:	00 00                	add    BYTE PTR [rax],al
  403edf:	00 e8                	add    al,ch
  403ee1:	3f                   	(bad)
  403ee2:	40 00 00             	rex add BYTE PTR [rax],al
  403ee5:	00 00                	add    BYTE PTR [rax],al
  403ee7:	00 02                	add    BYTE PTR [rdx],al
  403ee9:	00 00                	add    BYTE PTR [rax],al
  403eeb:	00 00                	add    BYTE PTR [rax],al
  403eed:	00 00                	add    BYTE PTR [rax],al
  403eef:	00 30                	add    BYTE PTR [rax],dh
  403ef1:	00 00                	add    BYTE PTR [rax],al
  403ef3:	00 00                	add    BYTE PTR [rax],al
  403ef5:	00 00                	add    BYTE PTR [rax],al
  403ef7:	00 14 00             	add    BYTE PTR [rax+rax*1],dl
  403efa:	00 00                	add    BYTE PTR [rax],al
  403efc:	00 00                	add    BYTE PTR [rax],al
  403efe:	00 00                	add    BYTE PTR [rax],al
  403f00:	07                   	(bad)
  403f01:	00 00                	add    BYTE PTR [rax],al
  403f03:	00 00                	add    BYTE PTR [rax],al
  403f05:	00 00                	add    BYTE PTR [rax],al
  403f07:	00 17                	add    BYTE PTR [rdi],dl
  403f09:	00 00                	add    BYTE PTR [rax],al
  403f0b:	00 00                	add    BYTE PTR [rax],al
  403f0d:	00 00                	add    BYTE PTR [rax],al
  403f0f:	00 f0                	add    al,dh
  403f11:	04 40                	add    al,0x40
  403f13:	00 00                	add    BYTE PTR [rax],al
  403f15:	00 00                	add    BYTE PTR [rax],al
  403f17:	00 07                	add    BYTE PTR [rdi],al
  403f19:	00 00                	add    BYTE PTR [rax],al
  403f1b:	00 00                	add    BYTE PTR [rax],al
  403f1d:	00 00                	add    BYTE PTR [rax],al
  403f1f:	00 c0                	add    al,al
  403f21:	04 40                	add    al,0x40
  403f23:	00 00                	add    BYTE PTR [rax],al
  403f25:	00 00                	add    BYTE PTR [rax],al
  403f27:	00 08                	add    BYTE PTR [rax],cl
  403f29:	00 00                	add    BYTE PTR [rax],al
  403f2b:	00 00                	add    BYTE PTR [rax],al
  403f2d:	00 00                	add    BYTE PTR [rax],al
  403f2f:	00 30                	add    BYTE PTR [rax],dh
  403f31:	00 00                	add    BYTE PTR [rax],al
  403f33:	00 00                	add    BYTE PTR [rax],al
  403f35:	00 00                	add    BYTE PTR [rax],al
  403f37:	00 09                	add    BYTE PTR [rcx],cl
  403f39:	00 00                	add    BYTE PTR [rax],al
  403f3b:	00 00                	add    BYTE PTR [rax],al
  403f3d:	00 00                	add    BYTE PTR [rax],al
  403f3f:	00 18                	add    BYTE PTR [rax],bl
  403f41:	00 00                	add    BYTE PTR [rax],al
  403f43:	00 00                	add    BYTE PTR [rax],al
  403f45:	00 00                	add    BYTE PTR [rax],al
  403f47:	00 fe                	add    dh,bh
  403f49:	ff                   	(bad)
  403f4a:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
  403f4d:	00 00                	add    BYTE PTR [rax],al
  403f4f:	00 90 04 40 00 00    	add    BYTE PTR [rax+0x4004],dl
  403f55:	00 00                	add    BYTE PTR [rax],al
  403f57:	00 ff                	add    bh,bh
  403f59:	ff                   	(bad)
  403f5a:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
  403f5d:	00 00                	add    BYTE PTR [rax],al
  403f5f:	00 01                	add    BYTE PTR [rcx],al
  403f61:	00 00                	add    BYTE PTR [rax],al
  403f63:	00 00                	add    BYTE PTR [rax],al
  403f65:	00 00                	add    BYTE PTR [rax],al
  403f67:	00 f0                	add    al,dh
  403f69:	ff                   	(bad)
  403f6a:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
  403f6d:	00 00                	add    BYTE PTR [rax],al
  403f6f:	00 86 04 40 00 00    	add    BYTE PTR [rsi+0x4004],al
	...

Disassembly of section .got:

0000000000403fd8 <.got>:
	...

Disassembly of section .got.plt:

0000000000403fe8 <_GLOBAL_OFFSET_TABLE_>:
  403fe8:	08 3e                	or     BYTE PTR [rsi],bh
  403fea:	40 00 00             	rex add BYTE PTR [rax],al
	...
  403ffd:	00 00                	add    BYTE PTR [rax],al
  403fff:	00 36                	add    BYTE PTR [rsi],dh
  404001:	10 40 00             	adc    BYTE PTR [rax+0x0],al
  404004:	00 00                	add    BYTE PTR [rax],al
  404006:	00 00                	add    BYTE PTR [rax],al
  404008:	46 10 40 00          	rex.RX adc BYTE PTR [rax+0x0],r8b
  40400c:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .data:

0000000000404010 <__data_start>:
	...

0000000000404018 <__dso_handle>:
	...

Disassembly of section .bss:

0000000000404020 <completed.0>:
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp spl,BYTE PTR [r8]
   5:	28 44 65 62          	sub    BYTE PTR [rbp+riz*2+0x62],al
   9:	69 61 6e 20 31 32 2e 	imul   esp,DWORD PTR [rcx+0x6e],0x2e323120
  10:	32 2e                	xor    ch,BYTE PTR [rsi]
  12:	30 2d 31 34 29 20    	xor    BYTE PTR [rip+0x20293431],ch        # 20293449 <_end+0x1fe8f421>
  18:	31 32                	xor    DWORD PTR [rdx],esi
  1a:	2e 32 2e             	cs xor ch,BYTE PTR [rsi]
  1d:	30 00                	xor    BYTE PTR [rax],al
