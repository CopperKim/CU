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

public class SphereParticles implements Listener {

    @EventHandler
    public void EmeraldRightClicked(PlayerInteractEvent event) {

        Player player = event.getPlayer();
        World world = player.getWorld();

        if (player.getInventory().getItemInMainHand().getType() != Material.EMERALD) return;
        if (event.getAction() != Action.RIGHT_CLICK_AIR) return;

        Location location = player.getLocation();
        double radius = 3;
        int iMax = 10, jMax = 10;

        for (int j = -jMax; j <= jMax; j++) {
            for (int i = 0; i <= iMax; i++) {
                double theta = 2 * Math.PI * i / (double) iMax;
                double phi = Math.PI * j / (double) jMax;

                double x = radius * Math.sin(phi) * Math.cos(theta);
                double z = radius * Math.sin(phi) * Math.sin(theta);
                double y = radius * Math.cos(phi);

                Vector dir = new Vector(x, y, z);
                world.spawnParticle(Particle.HAPPY_VILLAGER, location.clone().add(dir), 1);
            }
        }
    }

}
