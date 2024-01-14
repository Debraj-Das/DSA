set mouse=a                     " Reset the mouse setting from defaults
aug vimStartup | au! | aug END  " Revert last positioned jump, as it is defined below
let g:skip_defaults_vim = 1     " Do not source defaults.vim again (after loading this system vimrc)
set encoding=utf-8
set ai                          " set auto-indenting on for programming
set showmatch                   " automatically show matching brackets.
set vb                          " turn on the "visual bell" 
set showmode                    " show the current mode
set wildmode=list:longest,longest:full   " Better command line completion
set wildmenu
set wildignore=*.docx,*.jpg,*.png,*.gif,*.pdf,*.pyc,*.exe,*.flv,*.img,*.xlsx
filetype on
filetype indent on
set smartindent						" even better autoindent (e.g. add indent after '{')
set nobackup							" No backup file
set nowritebackup
syntax on
set clipboard=unnamed
set clipboard^=unnamedplus
set relativenumber
set nu
set backspace=2
set laststatus=2
set autoread
set autoindent
set tabstop=3
set shiftwidth=3
set smarttab
set softtabstop=3
set foldmethod=manual "Fold the files as manual"
set path+=**

colorscheme elford
set shell=powershell.exe

" Only do this part when compiled with support for autocommands.
if has("autocmd")
    " Set UTF-8 as the default encoding for commit messages
    autocmd BufReadPre COMMIT_EDITMSG,MERGE_MSG,git-rebase-todo setlocal fileencoding=utf-8

    " Remember the positions in files with some git-specific exceptions"
    autocmd BufReadPost *
      \ if line("'\"") > 0 && line("'\"") <= line("$")
      \           && &filetype !~# 'commit\|gitrebase'
      \           && expand("%") !~ "ADD_EDIT.patch"
      \           && expand("%") !~ "addp-hunk-edit.diff" |
      \   exe "normal! g`\"" |
      \ endif

      autocmd BufNewFile,BufRead *.patch set filetype=diff

      autocmd Filetype diff
      \ highlight WhiteSpaceEOL ctermbg=red |
      \ match WhiteSpaceEOL /\(^+.*\)\@<=\s\+$/
endif 


call plug#begin('~/AppData/Local/nvim/plugged')

Plug 'scrooloose/nerdtree'
Plug 'itchyny/lightline.vim'
Plug 'tpope/vim-fugitive'
Plug 'vimwiki/vimwiki'
Plug 'tpope/vim-commentary'
Plug 'bfrg/vim-cpp-modern'
Plug 'vim-syntastic/syntastic'
Plug 'kshenoy/vim-signature'
Plug 'morhetz/gruvbox'
Plug 'tpope/vim-surround'

call plug#end()

"Mapping the key"
noremap <TAB> %

"normal mode key binding
nnoremap <enter> o<esc>
nnoremap <C-l> :w <CR>
nnoremap <C-n> :tabnew <CR>
nnoremap <C-Down> :m+1<CR>
nnoremap <C-Up> :m-2<CR>
nnoremap <C-k> :q <CR>
nnoremap d "_d

"virtual mode key binding
vnoremap <C-Down> :m '>+1<CR>gv=gv
vnoremap <C-Up> :m '<-2<CR>gv=gv 
vnoremap < <gv
vnoremap > >gv
vnoremap d "_d

"insert mode key binding
inoremap <C-l> <esc>
inoremap <C-k> <CR>}<Esc>ko
inoremap <C-j> <Esc>o
inoremap <C-h> <C-w>
inoremap <C-Down> <esc>:m+1<CR>
inoremap <C-Up> <esc>:m-2<CR>

let mapleader = " "

noremap <Leader>j <esc>:tabprevious <CR>
noremap <Leader>k <esc>:tabnext <CR>
noremap <Leader>y <esc>:%y+<CR>
noremap <Leader>v <C-v>
noremap <Leader>r <C-r>

nnoremap <Leader>s :source %<CR>
nnoremap <Leader>f :NERDTreeToggle<CR>:NERDTreeRefreshRoot<CR>
nnoremap <leader>h :set hlsearch!<CR>
nnoremap <leader>t :Cpp<CR>


"--- Template of Different language ---"
autocmd BufNewFile *.cpp 0r ~/Desktop/CP/CPSetup/Main_Boiler_Template.cpp 


command! Vrc call VimrcOpen()
function! VimrcOpen()
	tabedit ~/AppData/Local/nvim/init.vim
endfunction

command! Cpp call CppSnippts()
function! CppSnippts()
	tabedit ~/Desktop/CP/CPSetup/CppSnippts.cpp
endfunction
