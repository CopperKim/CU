package org.tutorial.minecraftplugintutorial;

import org.bukkit.plugin.java.JavaPlugin;

public final class MinecraftPluginTutorial extends JavaPlugin {

    @Override
    public void onEnable() {
        // Plugin startup logic
        getLogger().info("@ PluginTutorial enabled");
        getServer().getPluginManager().registerEvents(new CowCannonListener(), this);
        getServer().getPluginManager().registerEvents(new LazerWithBlazeRodListener(), this);
        getServer().getPluginManager().registerEvents(new SphereParticles(), this);
        getCommand("cow").setExecutor(new CowCommand());
    }

    @Override
    public void onDisable() {
        // Plugin shutdown logic
        getLogger().info("@ PluginTutorial disabled");
    }

    public static MinecraftPluginTutorial getInstance() {
        return getPlugin(MinecraftPluginTutorial.class);
    }
}
