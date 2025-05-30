package org.tutorial.minecraftplugintutorial;

import org.bukkit.ChatColor;
import org.bukkit.command.Command;
import org.bukkit.command.CommandExecutor;
import org.bukkit.command.CommandSender;
import org.bukkit.command.TabExecutor;
import org.bukkit.entity.Cow;
import org.bukkit.entity.Player;
import org.bukkit.metadata.FixedMetadataValue;
import org.jetbrains.annotations.NotNull;
import org.jetbrains.annotations.Nullable;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CowCommand implements CommandExecutor, TabExecutor {

    @Override
    public boolean onCommand(@NotNull CommandSender sender, @NotNull Command command, @NotNull String label, @NotNull String[] args) {

        if (!(sender instanceof Player))
            sender.sendMessage("Only Players can execute this command");

        if (args.length > 1) return false;

        Player player = (Player) sender;

        Cow cow = player.getWorld().spawn(player.getLocation(), Cow.class);

        if (args.length == 1 && args[0].equalsIgnoreCase("baby")) cow.setBaby();

        cow.setMetadata("CowCannon", new FixedMetadataValue(MinecraftPluginTutorial.getInstance(), true));

        cow.setCustomName(ChatColor.RED + "Milk me!");
        cow.setCustomNameVisible(true);

        return true;
    }

    @Override
    public @Nullable List<String> onTabComplete(@NotNull CommandSender sender, @NotNull Command command, @NotNull String label, @NotNull String[] args) {

        if (args.length == 1) return Arrays.asList("baby");

        return new ArrayList<>();
    }
}
