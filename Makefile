include maketools/common_config.mk
include maketools/source_list.mk

NAME := philo

SRC_LIB := $(call source_list,src/lib)
SRC_MAIN := $(call source_list,src/mandatory)
SRC_BONUS := $(call source_list,src/bonus)

SRC := $(if $(BONUS_MODE),$(SRC_BONUS),$(SRC_MAIN)) $(SRC_LIB)

OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LDLIBS += -lpthread

all: $(NAME)

$(NAME): $(OBJ)

include maketools/common_rules.mk

-include $(OBJ:.o=.d)
