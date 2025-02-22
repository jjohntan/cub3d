#!/bin/bash
GREEN="\033[0;32m"
RED="\033[0;31m"
PURPLE="\033[0;35m"
YELLOW="\033[0;33m"
NC="\033[0m" # No Color

run_command() {
    INPUT="$1"
    echo -e "${PURPLE}Input: ${NC}"
    echo -e "$INPUT"

    # Capture the command output
    OUTPUT=$(./cub3d "$INPUT" 2>&1)

    echo -e "${PURPLE}Output: ${NC}"
    echo -e "$OUTPUT"

    # Run valgrind and capture its output
    valgrind -q --leak-check=full --error-exitcode=222 ./cub3d "$INPUT" &>/dev/null
    if [ $? -eq 222 ]; then
        echo -e "${PURPLE}Valgrind: ${RED}KO${NC}"
    else
        echo -e "${PURPLE}Valgrind: ${GREEN}OK${NC}"
    fi
    echo -e "${GREEN}--------------------------------------------------------------------${NC}"
}

    echo -e "\n\n${YELLOW} Wrong configuration ${NC}"
    echo -e "${YELLOW} =================== ${NC}\n\n"

    run_command "./_map/bad/color_invalid_rgb.cub"
    run_command "./_map/bad/color_missing.cub"
    run_command "./_map/bad/color_missing_ceiling_rgb.cub"
    run_command "./_map/bad/color_missing_floor_rgb.cub"
    run_command "./_map/bad/color_none.cub"
    run_command "./_map/bad/color_not_number.cub"
    run_command "./_map/bad/duplicate_color.cub"
    run_command "./_map/bad/duplicate_texture.cub"
    run_command "./_map/bad/empty.cub"
    run_command "./_map/bad/file_letter_end.cub"
    run_command "./_map/bad/filetype_missing"
    run_command "./_map/bad/filetype_wrong.buc"
    run_command "./_map/bad/invalid_identifier.cub"
    run_command "./_map/bad/invalid_texture.cub"
    run_command "./_map/bad/map_first.cub"
    run_command "./_map/bad/map_middle.cub"
    run_command "./_map/bad/map_missing.cub"
    run_command "./_map/bad/map_only.cub"
    run_command "./_map/bad/map_too_small.cub"
    run_command "./_map/bad/missing_color_value.cub"
    run_command "./_map/bad/missing_info.cub"
    run_command "./_map/bad/new_line_map.cub"
    run_command "./_map/bad/no_texture_path.cub"
    run_command "./_map/bad/player_multiple.cub"
    run_command "./_map/bad/player_none.cub"
    run_command "./_map/bad/player_on_edge.cub"
    run_command "./_map/bad/test_whitespace.cub"
    run_command "./_map/bad/test_whitespace_2.cub"
    run_command "./_map/bad/test_whitespace_3.cub"
    run_command "./_map/bad/textures_dir.cub"
    run_command "./_map/bad/textures_duplicates.cub"
    # run_command "./_map/bad/textures_forbidden.cub"
    run_command "./_map/bad/textures_invalid.cub"
    run_command "./_map/bad/textures_missing.cub"
    run_command "./_map/bad/textures_none.cub"
    run_command "./_map/bad/textures_not_xpm.cub"
    run_command "./_map/bad/wall_hole_east.cub"
    run_command "./_map/bad/wall_hole_north.cub"
    run_command "./_map/bad/wall_hole_south.cub"
    run_command "./_map/bad/wall_hole_west.cub"
    run_command "./_map/bad/wall_none.cub"
    run_command "./_map/bad/player_out_of_map.cub"
    run_command "./_map/bad/wall_hole_not_rect.cub"

    
    # echo -e "\n\n${YELLOW} Correct configuration ${NC}"
    # echo -e "${YELLOW} ===================== ${NC}\n\n"

    # run_command "./_map/good/cheese_maze.cub"
    # run_command "./_map/good/creepy.cub"
    # run_command "./_map/good/dungeon.cub"
    # run_command "./_map/good/have_space.cub"
    # run_command "./_map/good/library.cub"
    # run_command "./_map/good/matrix.cub"
    # run_command "./_map/good/sad_face.cub"
    # run_command "./_map/good/square_map.cub"
    # run_command "./_map/good/subject_map.cub"
    # run_command "./_map/good/test_map.cub"
    # run_command "./_map/good/test_map_2.cub"
    # run_command "./_map/good/test_map_hole.cub"
    # run_command "./_map/good/test_pos_bottom.cub"
    # run_command "./_map/good/test_pos_left.cub"
    # run_command "./_map/good/test_pos_right.cub"
    # run_command "./_map/good/test_pos_top.cub"
    # run_command "./_map/good/test_textures.cub"
    # run_command "./_map/good/test_whitespace.cub"
    # run_command "./_map/good/triangle.cub"
    # run_command "./_map/good/valid_map.cub"
    # run_command "./_map/good/works.cub"
    # run_command "./_map/good/mini.cub"
    # run_command "./_map/good/bonus1.cub"
    # run_command "./_map/good/bonus2.cub"