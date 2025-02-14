
a.out:     file format elf64-x86-64


Disassembly of section .text:

0000000000401550 <Base::~Base()>:
  401550:	55                   	push   %rbp
  401551:	48 89 e5             	mov    %rsp,%rbp
  401554:	48 83 ec 10          	sub    $0x10,%rsp
  401558:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  40155c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401560:	48 c7 00 a0 20 40 00 	movq   $0x4020a0,(%rax)
  401567:	bf 80 40 40 00       	mov    $0x404080,%edi
  40156c:	be 30 20 40 00       	mov    $0x402030,%esi
  401571:	e8 ea fa ff ff       	call   401060 <std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)@plt>
  401576:	48 89 c1             	mov    %rax,%rcx
  401579:	48 89 4d f0          	mov    %rcx,-0x10(%rbp)
  40157d:	e9 00 00 00 00       	jmp    401582 <Base::~Base()+0x32>
  401582:	48 8b 7d f0          	mov    -0x10(%rbp),%rdi
  401586:	be 0a 00 00 00       	mov    $0xa,%esi
  40158b:	e8 f0 fa ff ff       	call   401080 <std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char)@plt>
  401590:	e9 00 00 00 00       	jmp    401595 <Base::~Base()+0x45>
  401595:	48 83 c4 10          	add    $0x10,%rsp
  401599:	5d                   	pop    %rbp
  40159a:	c3                   	ret    
  40159b:	48 89 c7             	mov    %rax,%rdi
  40159e:	e8 1d 00 00 00       	call   4015c0 <__clang_call_terminate>
  4015a3:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
  4015aa:	00 00 00 
  4015ad:	0f 1f 00             	nopl   (%rax)

00000000004015b0 <Base::~Base()>:
  4015b0:	55                   	push   %rbp
  4015b1:	48 89 e5             	mov    %rsp,%rbp
  4015b4:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  4015b8:	0f 0b                	ud2    // undefined instruction
  4015ba:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000401410 <Derived::~Derived()>:
  401410:	55                   	push   %rbp
  401411:	48 89 e5             	mov    %rsp,%rbp
  401414:	48 83 ec 30          	sub    $0x30,%rsp
  401418:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  40141c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401420:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
  401424:	48 c7 00 18 20 40 00 	movq   $0x402018,(%rax)
  40142b:	bf 80 40 40 00       	mov    $0x404080,%edi
  401430:	be 48 20 40 00       	mov    $0x402048,%esi
  401435:	e8 26 fc ff ff       	call   401060 <std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)@plt>
  40143a:	48 89 c1             	mov    %rax,%rcx
  40143d:	48 89 4d e0          	mov    %rcx,-0x20(%rbp)
  401441:	e9 00 00 00 00       	jmp    401446 <Derived::~Derived()+0x36>
  401446:	48 8b 7d e0          	mov    -0x20(%rbp),%rdi
  40144a:	be 0a 00 00 00       	mov    $0xa,%esi
  40144f:	e8 2c fc ff ff       	call   401080 <std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char)@plt>
  401454:	e9 00 00 00 00       	jmp    401459 <Derived::~Derived()+0x49>
  401459:	48 8b 7d d8          	mov    -0x28(%rbp),%rdi
  40145d:	e8 ee 00 00 00       	call   401550 <Base::~Base()>
  401462:	48 83 c4 30          	add    $0x30,%rsp
  401466:	5d                   	pop    %rbp
  401467:	c3                   	ret    
  401468:	48 8b 7d d8          	mov    -0x28(%rbp),%rdi
  40146c:	48 89 c1             	mov    %rax,%rcx
  40146f:	89 d0                	mov    %edx,%eax
  401471:	48 89 4d f0          	mov    %rcx,-0x10(%rbp)
  401475:	89 45 ec             	mov    %eax,-0x14(%rbp)
  401478:	e8 d3 00 00 00       	call   401550 <Base::~Base()>
  40147d:	48 8b 7d f0          	mov    -0x10(%rbp),%rdi
  401481:	e8 3a 01 00 00       	call   4015c0 <__clang_call_terminate>
  401486:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
  40148d:	00 00 00 

00000000004014e0 <Derived::~Derived()>:
  4014e0:	55                   	push   %rbp
  4014e1:	48 89 e5             	mov    %rsp,%rbp
  4014e4:	48 83 ec 10          	sub    $0x10,%rsp
  4014e8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  4014ec:	48 8b 7d f8          	mov    -0x8(%rbp),%rdi
  4014f0:	48 89 7d f0          	mov    %rdi,-0x10(%rbp)
  4014f4:	e8 17 ff ff ff       	call   401410 <Derived::~Derived()>
  4014f9:	48 8b 7d f0          	mov    -0x10(%rbp),%rdi
  4014fd:	e8 fe fe ff ff       	call   401400 <Base::operator delete(void*)>
  401502:	48 83 c4 10          	add    $0x10,%rsp
  401506:	5d                   	pop    %rbp
  401507:	c3                   	ret    
  401508:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  40150f:	00 

...
