<?php
if (isset($data)):
    foreach ($data as $value): ?>
        <div>
            <?php echo $value->title ?>
        </div>
        <div>
            <?php echo format_date($value->created) ?>
        </div>
    <?php endforeach;
else: ?>
    <div>
        Nodes missing
    </div>
<?php endif; ?>
