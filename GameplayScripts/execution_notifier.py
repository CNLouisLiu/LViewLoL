from lview import *
import commons.damage_calculator as damage_calculator

lview_script_info = {
	"script": "Execution notifier",
	"author": "orkido",
	"description": "Shows message if a enemy champion can be executed with an ability"
}


def lview_load_cfg(cfg):
	pass

def lview_save_cfg(cfg):
	pass

def lview_draw_settings(game, ui):
	pass

def lview_update(game, ui):
    damage_spec = damage_calculator.get_damage_specification(game.player)
    if damage_spec is None:
        # Current champion is not supported
        return

    for champ in game.champs:
        if champ.is_enemy_to(game.player):
            dmg = damage_spec.calculate_damage(game.player, champ)

            if champ.health <= dmg:
                game.draw_circle_filled(game.world_to_screen(champ.pos), 100.0, 100, Color.RED)
