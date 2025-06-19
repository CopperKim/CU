package org.tutorial.minecraftplugintutorial;

import org.bukkit.Location;
import org.bukkit.Material;
import org.bukkit.Particle;
import org.bukkit.World;
import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.block.Action;
import org.bukkit.event.player.PlayerInteractEvent;
import org.bukkit.util.Vector;

public class LazerWithBlazeRodListener implements Listener {

    @EventHandler
    public void itemRightClicked(PlayerInteractEvent event) {

        Player player = (Player) event.getPlayer();
        World world = player.getWorld();

        if (event.getAction() != Action.RIGHT_CLICK_AIR) return;

        if (player.getInventory().getItemInMainHand().getType() == Material.BLAZE_ROD) {
            Location pos = player.getLocation();
            Vector dir = (Vector) player.getLocation().getDirection().multiply(0.4);
            int count = 0;

            while (world.getBlockAt(pos).getType() == Material.AIR && count++ <= 100) {
                world.spawnParticle(Particle.HEART, pos, 1);
                pos.add(dir);
            }

            world.createExplosion(pos, 10F);
        }
    }
}
