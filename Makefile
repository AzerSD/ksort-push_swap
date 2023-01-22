# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asioud <asioud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 05:57:40 by asioud            #+#    #+#              #
#    Updated: 2023/01/22 08:02:07 by asioud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
BNAME	=	checker
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g

HFILES	=	./includes/push_swap.h
HBNS	=	./bonus/checker.h
LIBFT	=	./libft/libft.a
OUTDIR	=	./obj/
INDIR	=	./src/
INBNS	=	./bonus/
OUTBNS	=	./bonus/obj/
ARGS	=   74 488 256 245 7 225 57 342 138 228 31 194 357 393 334 114 306 196 173 315 76 41 280 414 15 286 13 461 429 387 220 32 390 75 338 167 468 146 320 373 254 190 370 448 316 275 94 343 433 371 496 382 384 115 9 227 100 56 349 224 309 497 172 39 193 392 311 326 451 408 487 78 336 288 492 475 361 440 92 402 378 281 246 260 458 137 318 471 90 291 43 199 213 302 36 305 470 279 453 491 455 66 214 252 489 399 233 272 247 242 327 116 200 67 109 495 454 330 438 160 341 457 463 204 133 217 432 37 129 20 261 44 389 391 460 206 8 45 257 5 405 271 297 232 400 410 112 148 145 10 80 459 409 12 101 500 425 209 72 237 407 367 6 119 435 423 360 147 420 131 89 436 83 241 445 307 218 308 444 58 166 91 216 211 135 183 268 314 395 223 269 262 169 276 16 107 340 368 125 186 49 366 164 51 310 380 52 313 96 379 398 162 243 14 403 98 319 278 141 465 478 17 192 25 466 85 198 171 386 130 142 388 362 222 4 274 365 374 207 40 113 63 442 258 337 187 161 154 427 424 93 443 285 301 64 108 277 364 28 483 263 482 346 295 226 397 437 205 283 103 132 230 298 152 34 59 481 439 156 419 118 447 26 412 485 208 178 168 221 411 251 219 150 499 197 356 179 375 418 248 264 188 48 106 335 299 30 95 359 182 201 143 417 372 27 175 110 238 332 38 255 71 428 396 421 42 259 54 69 355 303 104 70 158 480 159 381 383 165 348 363 321 202 289 191 189 176 479 122 282 473 140 292 139 128 22 111 339 2 333 29 323 253 385 296 431 35 284 181 180 229 347 212 472 416 426 249 68 494 324 234 126 462 329 441 376 81 153 273 174 84 215 474 312 3 195 477 86 102 87 121 239 163 464 136 184 293 328 149 358 50 62 322 267 331 1 406 55 353 476 23 300 61 344 484 401 82 452 469 157 490 235 97 77 236 170 250 105 46 369 244 325 123 124 434 304 127 19 493 354 350 185 155 449 177 21 73 422 317 450 53 151 345 47 18 290 486 203 351 11 24 144 99 294 120 287 270 79 498 210 65 60 430 456 446 394 117 266 467 377 134 415 413 265 240 404 231 88 33 352 

B_RED		:= \033[1;31m
B_GREEN		:= \033[1;32m
GREEN 		:= \033[0;32m
B_BLUE 		:= \033[1;34m
U_BLUE		:= \033[4;36m
END_COLOR	:= \033[0m

SRC		=	\
			$(INDIR)push_swap.c \
			$(INDIR)parse.c \
			$(INDIR)instructions.c \
			$(INDIR)sort.c \
			$(INDIR)sort_utils.c \
			$(INDIR)stack_utils.c

SRC_BNS	=	\
			$(INBNS)checker.c \
			$(INBNS)instructions_b.c \
			$(INBNS)instructions.c \
			$(INBNS)parse.c \
			$(INBNS)utils.c \
			
OBJ		=	$(SRC:$(INDIR)%.c=$(OUTDIR)%.o)
OBJ_BNS =	$(SRC_BNS:$(INBNS)%.c=$(OUTBNS)%.o)

all		:	$(NAME)
bonus	:	$(BNAME)

$(NAME)	 :	$(OBJ) # final compilation
	@cd libft && make
	@$(CC) $(CFLAGS)  $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(B_GREEN)DONE"
	@echo "\n$(B_RED)Use this link to generate numbers:"
	@echo "$(U_BLUE)https://numbergenerator.org/randomnumbergenerator/lottery#!numbers=500&low=-2147483648&high=2147483647&unique=true&csv=&oddeven=&oddqty=0&sorted=false&addfilters=$(END_COLOR)"
	@echo "\n$(B_RED)Go on :D $(B_BLUE)./push_swap \"2 0 3 1 5 4\"\n"


$(OUTDIR)%.o:	$(INDIR)%.c $(HFILES)  # create obj files
	@mkdir -p $(OUTDIR)
	@echo "$(B_GREEN)Compiling: $(GREEN)$(notdir $<) 🔨"
	@$(CC) $(CFLAGS) -c $< -o $@


$(OUTBNS)%.o:	$(INBNS)%.c $(HBNS)  # create obj files
	@mkdir -p $(OUTBNS)
	@echo "$(B_GREEN)Compiling: $(GREEN)$(notdir $<) 🔨"
	@$(CC) $(CFLAGS) -c $< -o $@


$(BNAME) :	$(OBJ_BNS)
	@cd libft && make
	@$(CC) $(CFLAGS)  $(OBJ_BNS) $(LIBFT) -o $(BNAME)
	@echo "$(B_GREEN)BONUS DONE"
	@echo "\n$(B_RED)Go on :D $(B_BLUE)./checker ARGS COMMANDS\n"



leaks :
	@valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --error-limit=no --tool=memcheck -s ./push_swap $(ARGS)

bleaks: 
	@./push_swap $(ARGS) | valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --error-limit=no --tool=memcheck -s ./checker $(ARGS)

clean :
	@cd libft && make clean
	@rm -rf $(OUTDIR)

fclean :	clean
	@cd libft && make fclean
	@cd bonus && rm -rf obj
	@rm -f $(BNAME)
	@rm -f $(NAME)

re	:	fclean all

./PHONY: all clean fclean re
