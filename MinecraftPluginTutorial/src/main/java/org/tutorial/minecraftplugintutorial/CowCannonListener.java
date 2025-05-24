package org.tutorial.minecraftplugintutorial;

import org.bukkit.Material;
import org.bukkit.entity.Cow;
import org.bukkit.entity.Entity;
import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.player.PlayerInteractEntityEvent;
import org.bukkit.inventory.EquipmentSlot;
import org.bukkit.permissions.PermissionAttachment;
import org.bukkit.permissions.PermissionAttachmentInfo;

import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

public class CowCannonListener implements Listener {

    Map<UUID, PermissionAttachment> permissions = new HashMap<UUID, PermissionAttachment>();

    @EventHandler
    public void onEntityRightClick(PlayerInteractEntityEvent event) {

        if (event.getHand() != EquipmentSlot.HAND) return;

        Player player = (Player) event.getPlayer();
        Entity entity = event.getRightClicked();

        for (PermissionAttachmentInfo permission : player.getEffectivePermissions()) {
            PermissionAttachment attachment = permission.getAttachment();

            System.out.println("Permission : " + permission.getPermission() + ", from : " + (attachment == null ? "default" : attachment.getPlugin().getName()));
        }

        if (permissions.containsKey(player.getUniqueId())) {
            PermissionAttachment permission = permissions.remove(player.getUniqueId());
            player.removeAttachment(permission);

            player.sendMessage("You are no longer have the permission.");

        } else {
            PermissionAttachment permission = player.addAttachment(MinecraftPluginTutorial.getInstance(), "minecraftplugintutorial.cow.use", true);

            permissions.put(player.getUniqueId(), permission);
            player.sendMessage("You now have the permission.");

        }

        if (entity instanceof Cow && entity.hasMetadata("CowCannon") && player.getItemInHand().getType() == Material.BUCKET) {

            if (!player.hasPermission("minecraftplugintutorial.cow.use")) {
                player.sendMessage("You don't have permission to explode cow");

                return;
            }

            Cow cow = (Cow) event.getRightClicked();

            cow.getWorld().createExplosion(cow.getLocation(), 2.5F);
        }
    }
}
